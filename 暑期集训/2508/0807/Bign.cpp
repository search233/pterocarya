//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

using namespace std;

const double PI = acos(-1.0);

class bign {
private:	//内部实现
    vector<int> num;  // 存储数字（低位在前，高位在后）
    bool neg = false; // 符号标记（true为负数）

    // 去除前导零并处理-0的情况
    void trim() {
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
        if (num.size() == 1 && num[0] == 0)
            neg = false;
    }

    // 绝对值
    bign _abs() const {
        bign res = *this;
        res.neg = false;
        return res;
    }

    // 比较绝对值大小（不考虑符号）
    // 返回1：|this| > |other|, 0：相等, -1：|this| < |other|
    int abs_compare(const bign& other) const {
        if (num.size() != other.num.size())
            return num.size() > other.num.size() ? 1 : -1;
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] != other.num[i])
                return num[i] > other.num[i] ? 1 : -1;
        }
        return 0;
    }

    // FFT实现（非递归）
    static void fft(vector<complex<double>>& a, bool invert) {
        int n = a.size();
        // 位逆置换
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;
            if (i < j)
                swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            complex<double> wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                complex<double> w(1);
                for (int j = 0; j < len / 2; j++) {
                    complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }

        if (invert) {
            for (complex<double>& x : a)
                x /= n;
        }
    }

public:
    // 构造函数
    bign() : num({0}), neg(false) {}  // 默认构造为0
    bign(long long x) {
        *this = x;
    }
    bign(const string& s) {
        from_string(s);
    }

    // 从字符串初始化
    void from_string(const string& s) {
        num.clear();
        neg = false;
        int start = 0;
        if (s[0] == '-') {
            neg = true;
            start = 1;
        }
        for (int i = s.size() - 1; i >= start; i--) {
            if (isdigit(s[i]))
                num.push_back(s[i] - '0');
        }
        trim();
    }

    // 从整数赋值
    bign& operator=(long long x) {
        num.clear();
        neg = (x < 0);
        x = abs(x);
        if (x == 0) num.push_back(0);
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        return *this;
    }

    // 转换为字符串
    string to_string() const {
        if (num.empty()) return "0";
        string s;
        if (neg) s += '-';
        for (int i = num.size() - 1; i >= 0; i--)
            s += char(num[i] + '0');
        return s;
    }

    // 重载比较运算符
    bool operator<(const bign& other) const {
        if (neg != other.neg) 
            return neg;
        if (neg) 
            return abs_compare(other) > 0;
        return abs_compare(other) < 0;
    }

    bool operator>(const bign& other) const { return other < *this; }
    bool operator<=(const bign& other) const { return !(*this > other); }
    bool operator>=(const bign& other) const { return !(*this < other); }
    bool operator==(const bign& other) const {
        return neg == other.neg && num == other.num;
    }
    bool operator!=(const bign& other) const { return !(*this == other); }

    // 重载算术运算符
    bign operator-() const {
        bign res = *this;
        res.neg = !neg;
        res.trim();
        return res;
    }

    bign operator+(const bign& other) const {
        if (neg == other.neg) {
            bign res = *this;
            int carry = 0;
            int max_size = max(num.size(), other.num.size());
            res.num.resize(max_size, 0);
            for (int i = 0; i < max_size; i++) {
                if (i < other.num.size())
                    res.num[i] += other.num[i];
                res.num[i] += carry;
                carry = res.num[i] / 10;
                res.num[i] %= 10;
            }
            if (carry)
                res.num.push_back(carry);
            return res;
        } else {
            if (neg)
                return other - (-*this);
            else
                return *this - (-other);
        }
    }

    bign operator-(const bign& other) const {
        if (neg != other.neg) {
            return *this + (-other);
        }
        if (abs_compare(other) < 0) {
            bign res = other - *this;
            res.neg = !neg;
            return res;
        }
        bign res = *this;
        int borrow = 0;
        for (int i = 0; i < res.num.size(); i++) {
            if (i < other.num.size())
                res.num[i] -= other.num[i];
            res.num[i] -= borrow;
            borrow = 0;
            if (res.num[i] < 0) {
                res.num[i] += 10;
                borrow = 1;
            }
        }
        res.trim();
        return res;
    }

    // 乘法（使用FFT优化）
    bign operator*(const bign& other) const {
        // 处理0或符号
        if (*this == 0 || other == 0) return bign(0);
        bign res;
        res.neg = neg ^ other.neg;

        // 将数字转换为复数向量
        vector<complex<double>> fa(num.begin(), num.end());
        vector<complex<double>> fb(other.num.begin(), other.num.end());
        
        // 扩展为2的幂
        int n = 1;
        while (n < fa.size() + fb.size()) 
            n <<= 1;
        fa.resize(n);
        fb.resize(n);

        // 执行FFT
        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] *= fb[i];
        fft(fa, true);

        // 处理进位
        res.num.resize(n);
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int digit = int(fa[i].real() + 0.5) + carry;
            carry = digit / 10;
            res.num[i] = digit % 10;
        }

        // 处理剩余进位
        while (carry) {
            res.num.push_back(carry % 10);
            carry /= 10;
        }
        res.trim();
        return res;
    }

    // 除法（长除法）
    bign operator/(const bign& other) const {
        if (other == 0) throw runtime_error("Division by zero");
        if (abs_compare(other) < 0) return bign(0);
        bign res, cur;
        res.num.resize(num.size());
        res.neg = neg ^ other.neg;
        
        for (int i = num.size() - 1; i >= 0; i--) {
            cur.num.insert(cur.num.begin(), num[i]);
            cur.trim();
            int quotient = 0;
            while (cur >= other._abs()) {
                cur = cur - other._abs();
                quotient++;
            }
            res.num[i] = quotient;
        }
        res.trim();
        return res;
    }

    // 取模运算
    bign operator%(const bign& other) const {
        bign quotient = *this / other;
        return *this - quotient * other;
    }

    // 友元函数：输出流
    friend ostream& operator<<(ostream& os, const bign& n) {
        os << n.to_string();
        return os;
    }

    // 友元函数：输入流
    friend istream& operator>>(istream& is, bign& n) {
        string s;
        is >> s;
        n.from_string(s);
        return is;
    }
};


void solve() {
    
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
│ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

*/
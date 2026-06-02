#include <bits/stdc++.h>
#include <cassert>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

const ll MOD = (int)1e9 + 7;
ll mod(ll num) {
    num %= MOD;
    if (num < 0) num += MOD;
    return num;
}

struct Op {
    // 广义加法 (标准：加法取模)
    static inline ll add(ll a, ll b) { 
        return mod(a + b); 
    }
    
    // 广义乘法 (标准：乘法取模)
    static inline ll mul(ll a, ll b) { 
        return mod(a * b); 
    }
    
    static inline const ll ZERO = 0; // 零元：用于填充矩阵初始值
    static inline const ll ONE  = 1; // 单位元：用于填充单位矩阵对角线
};


struct Mat {
    int r, c;
    vector<vector<ll>> v;

    // 构造函数：默认使用 Op::ZERO 初始化
    Mat(int row, int col) : r(row), c(col) {
        v.assign(r, vector<ll>(c, Op::ZERO));
    }

    // 重载乘法运算符
    Mat operator * (const Mat& b) const {
        Mat res(r, b.c); // 结果矩阵的大小为 r * b.c
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < c; ++k) {
                // 剪枝：如果当前左矩阵元素为零元，则跳过循环（对标准乘法和布尔乘法大幅加速）
                if (v[i][k] == Op::ZERO) continue; 
                
                for (int j = 0; j < b.c; ++j) {
                    ll next_val = Op::mul(v[i][k], b.v[k][j]);
                    res.v[i][j] = Op::add(res.v[i][j], next_val);
                }
            }
        }
        return res;
    }
};

// 矩阵快速幂
Mat qpow(Mat a, ll p) {
    Mat res(a.r, a.c);
    // 初始化广义单位矩阵
    for (int i = 0; i < a.r; ++i) {
        res.v[i][i] = Op::ONE;
    }

    while (p > 0) {
        if (p & 1) res = res * a;
        a = a * a;
        p >>= 1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;
    if (n == 1) {
        cout << 10 << '\n';
        return;
    }

    Mat ans(1, 10);
    ans.v[0].assign(10, 1);;
    ans.v[0][0] = 0;

    Mat m(10, 10);
    auto& mm = m.v;

/*
1 1 1 0 0 0 0 0 0 0
1 1 1 1 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 0 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 0 1 1 1 1 1 0
0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 1 1 1 1
0 0 0 0 0 0 0 1 1 1
*/

    mm[0] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    mm[1] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    mm[2] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    mm[3] = {0, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    mm[4] = {0, 0, 1, 1, 1, 1, 1, 0, 0, 0};
    mm[5] = {0, 0, 0, 1, 1, 1, 1, 1, 0, 0};
    mm[6] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
    mm[7] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    mm[8] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    mm[9] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};

    ans = ans * qpow(m, n - 1);

    ll sum = 0;
    
    for (auto i : ans.v[0]) sum = mod(sum + i);

    cout << sum;
}

int main() {
    
    __BUFF__

    int _ = 1;
    // cin >> _;

    while (_--) {
        solve();
        // cout << "-----------\n";
    }

    return 0;
}
/*
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░
*/
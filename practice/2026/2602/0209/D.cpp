//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

using i128 = __int128_t;

// 输出重载
ostream& operator<<(ostream& os, i128 x) {
    if (x == 0) {
        os << '0';
        return os;
    }
    if (x < 0) {
        os << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        int digit = (int)(x % 10);
        s.push_back('0' + digit);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    os << s;
    return os;
}

// 输入重载
istream& operator>>(istream& is, i128& x) {
    string s;
    is >> s;
    x = 0;
    bool neg = false;
    int i = 0;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < (int)s.size(); ++i) {
        x = x * 10 + (s[i] - '0');
    }
    if (neg) x = -x;
    return is;
}

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a; // gcd(a, 0) = a
    }
    i128 x1, y1;
    i128 g = exgcd(b, a % b, x1, y1);
    // 回溯更新系数
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

void solve() {
    i128 x, a, s;
    cin >> x >> a >> s;

    i128 c10, c20;
    i128 g = exgcd(a, s, c10, c20);

    if (x % g) {
        cout << "No\n";
        return;
    }

    c10 *= x / g;
    c20 *= x / g;

    i128 mx = LLONG_MAX;
    i128 c22 = -1, c12 = -1;
    i128 t = (c20 - c10) * g / (a + s);

    for (i128 tt : {t - 1, t, t + 1}) {
        i128 c11 = c10 + s * tt / g;
        i128 c21 = c20 - a * tt / g;

        if (c11 >= 0 && c21 >= 0) {
            if (max(c11, c21) < mx) {
                mx = max(c11, c21);
                c12 = c11;
                c22 = c21;
            }
        }
    }

    if (c22 >= 0 && c12 >= 0) {
        cout << "Yes\n";
        cout << c12 << ' ' << c22 << '\n';
    }
    else {
        cout << "No\n";
    }
} 

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------\n";
    }

    return 0;
}
/*
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │              
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐    
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │    
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
│Ctrl │Win │Alt │         Space         │Alt │ Fn │Menu│Ctrl│ │ ← │ ↓ │ → │
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

*/

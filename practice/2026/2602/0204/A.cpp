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
const ll MOD = 998244353;

ll inv;
int mod(ll num) {
    num %= MOD;
    if (num < 0) num += MOD;
    return num;
}


ll qpow(ll a, ll b) {
    ll ans = 1;
    ll fac = a;

    while (b) {
        if (b & 1) {
            ans = mod(ans * fac);
        }

        b >>= 1ll;
        fac = mod(fac * fac);
    }
    
    return ans;
}

void solve() {
    int c; cin >> c;
    vector<ll> p(8);

    for (int i = 1; i <= 7; ++i) {
        cin >> p[i];
        p[i] = mod(p[i] * inv);
    }

    vector<vector<ll>> num(10, vector<ll>(8));
    //           1  2  3  4  5  6  7
    num[0] = {1, 1, 1, 1, 0, 1, 1, 1};
    num[1] = {1, 0, 0, 1, 0, 0, 1, 0};
    num[2] = {1, 1, 0, 1, 1, 1, 0, 1};
    num[3] = {1, 1, 0, 1, 1, 0, 1, 1};
    num[4] = {1, 0, 1, 1, 1, 0, 1, 0};
    num[5] = {1, 1, 1, 0, 1, 0, 1, 1};
    num[6] = {1, 1, 1, 0, 1, 1, 1, 1};
    num[7] = {1, 1, 0, 1, 0, 0, 1, 0};
    num[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    num[9] = {1, 1, 1, 1, 1, 0, 1, 1};

    for (int i = 0; i <= 9; ++i) {
        for (int j = 1; j <= 7; ++j) {
            ll pp = p[j];
            if (num[i][j] == 0) pp = mod(1 - pp + MOD);
            num[i][0] = mod(num[i][0] * pp);
        }
    }

    auto fac = [&](int x) -> ll {
        ll ans = 1;
        int len = 0;
        do { 
            ++len;
            ans = mod(ans * num[x % 10][0]);
            x /= 10;
        } while (x);

        for (int i = 0; i < 4 - len; ++i) {
            ans = mod(ans * num[0][0]);
        }

        return ans;
    };

    ll ans = 0;
    for (int a = 0; a <= c; ++a) {
        int b = c - a;
        ans = mod(mod(fac(a) * fac(b)) + ans);
    }

    cout << ans << '\n';
} 

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;
    inv = qpow(100, MOD - 2);

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
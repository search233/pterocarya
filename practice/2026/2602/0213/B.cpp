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
const ll MAXN = 1000000; // 按题目需要设最大值

ll mod(ll num) {
    num %= MOD;
    if (num < 0) num += MOD;
    return num;
}

ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = mod(ans * a);
        a = mod(a * a) ;
        b >>= 1;
    }
    return ans;
}

struct Comb {
    int N;
    vector<long long> fac, inv;

    // 构造函数：预处理到 max_n
    Comb(int max_n) : N(max_n) {
        fac.resize(N + 1);
        inv.resize(N + 1);
        fac[0] = 1;
        for (int i = 1; i <= N; ++i) {
            fac[i] = mod(fac[i - 1] * i);
        }

        inv[N] = qpow(fac[N], MOD - 2);
        for (int i = N; i >= 1; --i) {
            inv[i - 1] = mod(inv[i] * i);
        }
    }

    // 组合数 C(n, k)
    ll C(int n, int k) const {
        if (k < 0 || k > n || n < 0) return 0;
        return mod(mod(fac[n] * inv[k]) * inv[n - k]);
    }
}comb(MAXN);

void solve() {
    ll n, x, t;
    cin >> n >> x >> t;

    ll k = t + 1;

auto cal = [&](int l, int r) -> ll {
    if (l > 0 && x < l) return 0;
    if (r > 0 && n - x < r) return 0;
    if (l == 0 && x != 0) return 0;
    if (r == 0 && n - x != 0) return 0;

    ll fac1 = 1, fac0 = 1;
    if (l > 0) fac1 = comb.C(x - 1, l - 1);
    if (r > 0) fac0 = comb.C(n - x - 1, r - 1);

    return mod(fac1 * fac0);
};

    int cntl = (k + 1) / 2;
    int cntr = k / 2;

    ll sum = 0;
    sum = mod(sum + cal(cntl, cntr));
    sum = mod(sum + cal(cntr, cntl));

    cout << sum << '\n';
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

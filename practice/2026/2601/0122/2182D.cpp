//https://codeforces.com/problemset/problem/2182/D

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

ll mod (ll x) {
    return x % MOD;
}

ll qpow (ll a, ll b) {
    ll fac = a;
    ll ans = 1;

    while (b) {
        if (b & 1) {
            ans = mod(ans * fac);
        }

        b >>= 1ll;
        fac = mod(fac * fac);
    }

    return ans;
};



void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
    ll sum = 0;
    int cnt = 0;

    cin >> a[0];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] > mx) {
            cnt = 1;
            mx = a[i];
        } else if (a[i] == mx) {
            ++cnt;
        }
    }

    sum -= cnt * mx;

    int cost = (n - cnt) * (mx - 1)  - sum;
    int frt = a[0] - cost;

    if (frt < 0) {
        cout << "0\n";
        return;
    }
 
    frt = min(frt, n - cnt);
    
    vector<ll> fc, inv(n + 1);
    fc.push_back(1);

    for (ll i = 1; i <= n; ++i) {
        fc.push_back(mod(fc.back() * i));
    }

    inv[n] = qpow(fc[n], MOD - 2);

    for (int i = n; i > 0; --i) {
        inv[i - 1] = mod(inv[i] * i);
    }

    auto C = [&](int k, int x) {
        return mod(mod(fc[k] * inv[x]) * inv[k - x]);
    };

    // ll ans = 0;
    ll ans = mod(mod(fc[frt + cnt] * fc[n - frt - cnt]) * C(n - cnt, frt)); 


    // for (int i = 0; i <= frt; ++i) {
    //     ans = mod(ans + mod(mod(mod(mod(cnt * fc[cnt - 1 + i])) * fc[n - i - cnt]) * C(i, n - cnt)));
    // }
    
    cout << ans << '\n';
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
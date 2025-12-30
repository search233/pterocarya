//https://codeforces.com/problemset/problem/2151/D

#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

vector<ll> fac(N);
vector<ll> inv(N);

ll ksm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}


void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    
    ll sum = 0;

    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum != n || a[1] < 2) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 1, suma = 0;

    sum = (n & 1) ? 1 : 2;

    auto c = [&](ll x, ll y) -> ll {
        return (fac[x] * inv[x - y] % mod) * inv[y] % mod;
    };

    for (ll i=(n + 1) / 2 ; i>0 ; --i) {
        
        if (a[i] + suma > sum) {
            cout << 0 << '\n';
            return;
        }
        if (a[i] + suma < sum) {
            ans = ans * c(sum - suma, a[i]) % mod;
        }


        // cout << ans << '\n';

        sum += 2;
        suma += a[i];
    }

    // cout << sum << ' ' << suma << '\n';

    if (suma + 2 != sum) cout << 0 << '\n';
    else cout << ans << '\n';

} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for (ll i=1 ; i<N ; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    inv[N - 5] = ksm(fac[N - 5], mod - 2);

    for (ll i=N - 5 ; i>=1 ; --i) {
        inv[i - 1] = inv[i] * i % mod;

    }

    // auto c = [&](ll x, ll y) -> ll {
    //     return (fac[x] * inv[x - y] % mod) * inv[y] % mod;
    // };

    // for (int i=1 ; i<=10 ; ++i) {
    //     for (int j=0 ; j<=i ; ++j) {
    //         cout << c(i, j) << ' ';
    //     }
    // }

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------" << '\n';
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
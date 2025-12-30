//https://codeforces.com/problemset/problem/2143/D1

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  (int)1e9 + 7;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);

    for (int i=1 ; i<=n ; ++i) cin >> a[i];

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)));

    dp[0][0][0] = 1;

    for (int i=1 ; i<=n ; ++i) {

        for (int j=0 ; j<=n ; ++j) {
            for (int k=0 ; k<=j ; ++k) {

                dp[i][j][k] = (dp[i - 1][j][k] + dp[i][j][k]) % mod;

                if (a[i] >= j) dp[i][a[i]][k] = (dp[i - 1][j][k] + dp[i][a[i]][k]) % mod;

                else if (a[i] >= k) dp[i][j][a[i]] = (dp[i - 1][j][k] + dp[i][j][a[i]]) % mod;
            }
        }
    }

    ll ans = 0;

    for (int j=0 ; j<=n ; ++j) {
        for (int k=0 ; k<=j ; ++k) {
            // if (dp[n][j][k]) {
            //     cout << "j, k : " << j << ' ' << k << ' ' << dp[n][j][k] << '\n';
            // }
            ans = (ans + dp[n][j][k]) % mod;
        }
    }

    cout << ans << '\n';
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*

ll fastPower(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        
        if (b & 1) res = res * a % mod;
        
        a = a * a % mod;
		b >>= 1;
    }
    return res;
}

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
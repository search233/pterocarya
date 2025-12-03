//https://codeforces.com/gym/105486/problem/B

#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const ll mod =  (ll)1e9 + 7;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

ll dp[310][310][310][3]; // pos, a, b, pre
ll ans[310][310][310];

void solve() {
    int n, q; 
    cin >> n >> q;

    string s; cin >> s;

    s = ' ' + s;
    vector<int> pre(n + 1);
    for (int i=1 ; i<=n ; ++i) {
        pre[i] += pre[i - 1] + (s[i] == '?');
    }

    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));

    if (s[1] == '?') {
        dp[1][1][0][0] = 1;
        dp[1][0][1][1] = 1;
        dp[1][0][0][2] = 1;
    }
    else {
        dp[1][0][0][s[1] - 'a'] = 1;
    }

    for (int i=2 ; i<=n ; ++i) {
        for (int a=0 ; a<=pre[i] ; ++a) {
            for (int b=0 ; b + a<=pre[i] ; ++b) {
                if (s[i] == '?') {
                    if (a) {
                        ll bcnt = dp[i - 1][a - 1][b][1];
                        ll ccnt = dp[i - 1][a - 1][b][2];
                        dp[i][a][b][0] = (bcnt + ccnt) % mod;
                    }
                    if (b) {
                        ll acnt = dp[i - 1][a][b - 1][0];
                        ll ccnt = dp[i - 1][a][b - 1][2];
                        dp[i][a][b][1] = (acnt + ccnt) % mod;
                    }
                    if (pre[i] - a - b) {
                        ll acnt = dp[i - 1][a][b][0];
                        ll bcnt = dp[i - 1][a][b][1];
                        dp[i][a][b][2] = (acnt + bcnt) % mod;
                    }
                }
                else {
                    for (int ch=0 ; ch<3 ; ++ch) {
                        if (ch != s[i] - 'a') {
                            dp[i][a][b][s[i] - 'a'] += dp[i - 1][a][b][ch];
                            dp[i][a][b][s[i] - 'a'] %= mod;
                        }
                    }
                }
            }
        }
    }

    for (int a=0 ; a<=pre[n] ; ++a) {
        for (int b=0 ; b + a <= pre[n] ; ++b) {
            ans[a][b][pre[n] - a - b] = 0;
            for (int ch=0 ; ch<3 ; ++ch) {
                ans[a][b][pre[n] - a - b] += dp[n][a][b][ch];
                ans[a][b][pre[n] - a - b] %= mod;
            }
        }
    }

    for (int a=0 ; a<=300 ; ++a) {
        for (int b=0 ; b<=300 ; ++b) {
            for (int c=0 ; c<=300 ; ++c) {
                if (a) ans[a][b][c] += ans[a-1][b][c];
                if (b) ans[a][b][c] += ans[a][b-1][c];
                if (c) ans[a][b][c] += ans[a][b][c-1];
                if (a && b) ans[a][b][c] += mod - ans[a-1][b-1][c];
                if (a && c) ans[a][b][c] += mod - ans[a-1][b][c-1];
                if (b && c) ans[a][b][c] += mod - ans[a][b-1][c-1];
                if (a && b && c) ans[a][b][c] += ans[a-1][b-1][c-1];
                ans[a][b][c] %= mod;
            }
        }
    }

    for (int i=0 ; i<q ; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << ans[x][y][z] << '\n';
    }
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;

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
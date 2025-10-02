//https://www.luogu.com.cn/problem/P4147

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);


void solve() {
    int m, n;
    cin >> n >> m;
    vector<vector<bool>> graph(n + 5, vector<bool>(m + 5, 0));

    for (int i=1 ; i<=n ; ++i) {
        for (int j=1 ; j<=m ; ++j) {
            char ch; cin >> ch;
            if (ch == 'F') graph[i][j] = 1;
        }
    }

    vector<vector<int>> l(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> r(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> u(n + 5, vector<int>(m + 5, 0));

    for (int i=1 ; i<=n ; ++i) {
        for (int j=1 ; j<=m ; ++j) {
            if (graph[i][j]) 
                l[i][j] = l[i][j - 1] + 1;
        }
    }

    for (int i=1 ; i<=n ; ++i) {
        for (int j=m ; j>0 ; --j) {
            if (graph[i][j]) 
                r[i][j] = r[i][j + 1] + 1;
        }
    }

    int ans = 0;
    for (int i=1 ; i<=n ; ++i) {
        for (int j=1 ; j<=m ; ++j) {
            if (graph[i][j]) {
                u[i][j] = u[i - 1][j] + 1;

                if (graph[i - 1][j]) {
                    l[i][j] = min(l[i][j], l[i - 1][j]);
                    r[i][j] = min(r[i][j], r[i - 1][j]);
                } 
            }

            ans = max(ans, u[i][j] * (l[i][j] + r[i][j] - 1) );
        }
    }

    // for (int i=1 ; i<=n ; ++i) {
    //     for (int j=1 ; j<=m ; ++j) {
    //         cout << l[i][j] << " \n"[j == m];
    //     }
    // }
    // cout << '\n';

    // for (int i=1 ; i<=n ; ++i) {
    //     for (int j=1 ; j<=m ; ++j) {
    //         cout << r[i][j] << " \n"[j == m];
    //     }
    // }
    // cout << '\n';
    // for (int i=1 ; i<=n ; ++i) {
    //     for (int j=1 ; j<=m ; ++j) {
    //         cout << u[i][j] << " \n"[j == m];
    //     }
    // }

    cout << ans * 3 << '\n';
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;

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
//https://qoj.ac/contest/2562/problem/14690

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

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
    int n, m;
    cin >> n >> m;

    vector<int> c(n + 1);
    for (int i=1 ; i<=n ; ++i) cin >> c[i];

    vector<vector<int>> e(n + 1);
    for (int i=1 ; i<n ; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    e[1].push_back(-1);

    vector<int> cnt;
    vector<ll> sum(n + 1);
    vector<arr2> dfn(n + 1);

    auto dfs = [&](auto& dfs, int u, int fa) -> void {
        dfn[u][0] = cnt.size();

        if (e[u].size() == 1) return;

        for (int i=0 ; i<e[u].size() ; ++i) {
            if (e[u][i] == fa) {
                swap(e[u][0], e[u][i]);
            }
            else {
                cnt.push_back(e[u][i]);
                dfs(dfs, e[u][i], u);
                dfn[u][1] = cnt.size();
            }
        }

        sort(e[u].begin() + 1, e[u].end(), [&](int a, int b) -> bool {
            return c[a] < c[b];
        });

        c[u] = min(c[u], c[e[u][1]] + c[e[u][2]]);
    };
    dfs(dfs, 1, -1);

    auto cal = [&](auto& cal, int u) -> void {
        int f = e[u][0];

        if (~f) {
            int add = (e[f][1] == u) ? c[e[f][2]] : c[e[f][1]];

            sum[u] = sum[f] + add;
        }

        if (e[u].size() == 1) return;

        for (int i=1 ; i<e[u].size() ; ++i) {
            cal(cal, e[u][i]);
        }
    };
    cal(cal, 1);

    for (int i=0 ; i<m ; ++i) {
        int x, y; cin >> x >> y;

        if (dfn[x][0] > dfn[y][0] && dfn[x][0] <= dfn[y][1]) {
            cout << sum[x] - sum[y] << '\n';
        }  
        else {
            cout << "-1\n";
        }
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
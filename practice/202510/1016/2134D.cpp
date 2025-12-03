//https://codeforces.com/problemset/problem/2134/D

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


void solve() {
    int n; cin >> n;

    vector<int> cnt(n + 1, 0);
    vector<vector<int>> graph(n + 1);

    for (int i=1 ; i<n ; ++i) {
        int u, v; cin >> u >> v;

        ++cnt[u];
        ++cnt[v];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool f = 1;
    int s = 0;
    for (int i=1 ; i<=n ; ++i) {
        if (cnt[i] >= 3) f = 0;

        if (cnt[i] == 1) s = i;
    }

    if (f) {
        cout << "-1\n";
        return;
    }

    vector<int> fa(n + 1);

    auto bfs = [&]() -> int {
        vector<int> dep(n + 1, -1);
        queue<int> qu;

        qu.push(s);
        dep[s] = 1;

        int endp = s;

        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();

            endp = u;

            for (auto& v : graph[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    qu.push(v);
                    fa[v] = u;
                }
            }
        }

        return endp;
    };

    s = bfs();
    s = bfs();

    while (s != -1) {
        int nxt = fa[s];

        if (cnt[nxt] > 2) {
            cout << s << ' ' << nxt << ' ';

            for (auto& i : graph[nxt]) {
                if (i != s && i != fa[nxt]) {
                    cout << i << '\n';
                    return;
                }
            }
        }

        s = nxt;
    }

    cout << "-1\n";
} 
 
int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------\n
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
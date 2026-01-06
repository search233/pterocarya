//https://qoj.ac/contest/1828/problem/9570

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

    vector<vector<int>> e(n + 1) ;

    for (int i=1 ; i<=n ; ++i) {

        int x, y;
        cin >> x >> y;

        if (x) {
            e[i].push_back(x);
            e[x].push_back(i);
        }

        if (y) {
            e[i].push_back(y);
            e[y].push_back(i);
        }
    }

    auto query = [](int u, int v) -> int {
        cout << "? " << u << ' ' << v << endl;

        int t; cin >> t;

        return t;
    };

    int t = 0, s = 1, sz = n;
    vector<int> size(n + 1), time(n + 1);
    vector<int> mcs(n + 1), vis(n + 1);
    
    auto dfs =[&](auto& dfs, int u, int fa) -> void {

        size[u] = 1;
        mcs[u] = 0;

        for (auto v : e[u]) {

            if (v == fa || vis[v]) continue;

            dfs(dfs, v, u);
            size[u] += size[v];
        }
    };

    auto dfs1 = [&](auto& dfs1, int u, int fa) -> void {
        time[u] = t;

        for (auto v : e[u]) {
            if (vis[v] || v == fa) continue;

            dfs1(dfs1, v, u);
            mcs[u] = max(mcs[u], size[v]);
        }

        mcs[u] = max(mcs[u], sz - size[u]);
    };

    while (1) {
        ++t;

        dfs(dfs, s, -1);
        sz = size[s];

        dfs1(dfs1, s, -1);
        for (int i=1 ; i<=n ; ++i) {
            if (time[i] == t && mcs[s] > mcs[i]) {
                s = i;
            }
        }

        vector<int> son;
        for (auto v : e[s]) {
            if (vis[v]) continue;

            son.push_back(v);
        }

        sort(son.begin(), son.end(), [&](int a, int b){
            return size[a] > size[b];
        });

        int res;

        if (son.size() == 0) {
            cout << "! " << s << endl;
            return;
        }
        else if (son.size() == 1) {
            res = query(son[0], s);

            if (res == 0) {
                cout << "! " << son[0] << endl;
                return;
            }
            else {
                cout << "! " << s << endl;
                return;
            }
        }
        else if (son.size() == 2) {
            res = query(son[0], son[1]);

            if (res == 1) {
                cout << "! " << s << endl;
                return;
            }
            else {
                vis[s] = 1;
                s = son[0];

                if (res) s = son[1];
            }
        }
        else if (son.size() == 3) {
            res = query(son[0], son[1]);

            if (res == 1) {
                vis[son[0]] = 1;
                vis[son[1]] = 1;
                // cout << s << '\n';
            }
            else {
                vis[s] = 1;
                s = son[0];
                
                if (res) s = son[1];
            }
        }
    }
} 

int main() {
    
    // ios::sync_with_stdio(0);
    // cin.tie(0);

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
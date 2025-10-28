//

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

    auto find = [&](int s, int sz) -> int {

        int pos = -1;
        vector<int> mcs(n + 1), size(n + 1, 1);

        auto dfs = [&](auto& dfs, int u, int fa) -> void {
            for (auto v : e[u]) {
                if (v == fa) continue;

                dfs(dfs, v, u);

                size[u] += size[v];

                mcs[u] = max(mcs[u], size[v]);
            }

            mcs[u] = max(mcs[u], sz - size[u]);
            
            if (pos == -1 || mcs[u] < mcs[pos]) {
                pos = u;
            }
        };

        dfs(dfs, s, -1);

        return pos;
    };

    int sz = n;
    while (1) {

        int p = find(1, sz);

        if (e[p].size() == 1) {
            if (query(p, e[p][0]) == 0) {
                cout << "! " << p << endl;
            }
            else {
                cout << "! " << e[p][0] << endl;
            }
            return;
        }
        else if (e[p].size() == 2){
            int res = query(e[p][1], e[p][0]);
            if (res == 0) {

            }
            else if (res == 1) {
                cout << "! " << p << endl;
                return;
            }
            else {

            }
        }
    }
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
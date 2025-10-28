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

    int sz = n, s = 1;
    vector<int> mcs(n + 1), size(n + 1);

    auto fd = [&]() -> int {

        int pos = -1;

        for (int i=1 ; i<=n ; ++i) {
            mcs[i] = 0, size[i] = 1;
        }

        auto dfs = [&](auto& dfs, int u, int fa) -> void {

            // cout << "u : " << u << '\n';

            for (auto v : e[u]) {
                

                if (v == fa) continue;
                // cout << "v : " << v << '\n';

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

    auto print = [&]() -> void {

        cout << "---------\n";
      
        for (int j=0 ; j<e[s].size() ; ++j) {
            cout << size[e[s][j]] << ' ';
        }
        cout << '\n';


        cout << "s: " << s << '\n';
        cout << "sz: " << sz << '\n';
        cout << "---------\n";
    };

    while (1) {

        s = fd();
        int p = fd();

 
// print();
// cout << "p: " << p << '\n';

        sort(e[p].begin(), e[p].end(), [&](int a, int b) {
            return size[a] < size[b];
        });

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

            int res = query(e[p][0], e[p][1]);

            if (res == 0) {
                //p e[p][0]

                s = e[p][0];
                sz = size[e[p][0]];

                e[e[p][0]].erase(find(e[e[p][0]].begin(), e[e[p][0]].end(), p));
            }
            else if (res == 1) {
                cout << "! " << p << endl;
                return;
            }
            else {
                s = e[p][1];
                sz -= size[p];

                e[e[p][1]].erase(find(e[e[p][1]].begin(), e[e[p][1]].end(), p));
            }
        }
        else {

            int res = query(e[p][0], e[p][1]);

            if (res == 0) {
                //p e[p][0]

                s = e[p][0];
                sz = size[e[p][0]];

                e[e[p][0]].erase(find(e[e[p][0]].begin(), e[e[p][0]].end(), p));
                e[p].erase(e[p].begin());
            }
            else if (res == 1) {
                s = p;
                sz -= size[e[p][0]];
                sz -= size[e[p][1]];

                e[p].erase(e[p].begin(), e[p].begin() + 2);
            }
            else {
                s = e[p][1];
                sz = size[e[p][1]];

                e[e[p][1]].erase(find(e[e[p][1]].begin(), e[e[p][1]].end(), p));
            }
        }

        if (size[p] == 1) {
            cout << "! " << p << '\n';
            return ;
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
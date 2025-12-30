//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    auto cmp = [](arr3 x, arr3 y) -> bool {
        return x[2] > y[2];
    };

    priority_queue<arr3, vector<arr3>, decltype(cmp)> qu; // x, y, t
    vector e(n + 2, vector<int> (m + 2));
    
    for (int i = 0; i < a; ++i) {
        int x, y; cin >> x >> y;
        e[x][y] = 1;
        qu.push({x, y, 0});
    }

    map<arr2, int> mp;
    for (int i = 0; i < b; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        
        e[x][y] = 2;
        mp[{x, y}] = t;
    }
    
    auto ck = [&](int x, int y, int t) -> bool {
        if (x < 1 || y < 1 || x > n || y > m) {
            // cout << "f**k1\n";
            return false;
        }

        if (e[x][y] == 1) {
            // cout << "f**k2\n";
            return false;
        }

        if (e[x][y] == 2) {
            if (mp.count({x, y}) && mp[{x, y}] <= t) {
                mp.erase({x, y});
                return true;
            }
            else {
                // cout << "f**k3\n";
                return false;
            }
        }

        return true;
    };

    int T = 1;
    while (!qu.empty()) {
        auto [x, y, t] = qu.top();
        qu.pop();

        // cout << x << ' ' << y << ' ' << t << '\n';

        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (ck(xx, yy, t + 1)) {
                e[xx][yy] = 1;
                qu.push({xx, yy, t + 1});
            }
            if (e[xx][yy] == 2) {
                e[xx][yy] = 1;
                qu.push({xx, yy, mp[{xx, yy}]});
            }
            // cout << xx << ' ' << yy << ' ' << t + 1 << '\n';
        }

        T = t;
    }

    // for (auto [p, t] : mp) {
    //     T = max(T, t);
    // }

    cout << T << '\n';
} 

int main() {
    
    __BUFF__

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

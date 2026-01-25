//https://codeforces.com/problemset/problem/2193/F

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void solve() {
    int n;
    int xa, xb, ya, yb;
    cin >> n >> xa >> ya >> xb >> yb;


    vector<arr2> p(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i][1];
    }

    p.push_back({xa, ya});
    p.push_back({xb, yb});

    map<int, vector<int>> mp;

    for (int i = 0; i < n + 2; ++i) {
        mp[p[i][0]].push_back(p[i][1]);
    }


    vector<vector<int>> x;
    for (auto [xi, vec] : mp) {
        ranges::sort(vec);
        x.push_back(vec);
    }

    ll ans = xb - xa;

    // for (int i = 0; i < x.size(); ++i) {
    //     cout << i << "   ";
    //     for (int y : x[i]) {
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }
    int poss = xa;
    for (int i = 0; i < x.size() - 1; ++i) {
        int mn = INT_MAX;
        for (auto y : x[i]) {
            int pos = lower_bound(x[i + 1].begin(), x[i + 1].end(), y) - x[i + 1].begin();
            
            // cout <<"y =    " <<  y << '\n';
            if (pos < x[i + 1].size()) {
                // cout << x[i + 1][pos] << '\n';
                if (mn > abs(y - x[i + 1][pos]) + abs(y - poss)) {
                    mn = abs(y - x[i + 1][pos]) + abs(y - poss);
                    poss = x[i + 1][pos];
                }
            }

            --pos;
            if (pos >= 0) {
                // cout << x[i + 1][pos] << '\n';
                if (mn > abs(y - x[i + 1][pos]) + abs(y - poss)) {
                    mn = abs(y - x[i + 1][pos]) + abs(y - poss);
                    poss = x[i + 1][pos];
                }
            }
        }
        cout << "mn = " <<  mn << '\n';
        // cout << "------\n";
        ans += mn + x[i].back() - x[i].front();
    }

    cout << ans << '\n';
} 

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        cout << "-----------\n";
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
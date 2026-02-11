//https://codeforces.com/problemset/problem/2193/F

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<ll, 2>;
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
    int len = x.size();
    vector<arr2> dp(x.size());

    for (int i = 1; i < len; ++i) {
        auto dis1 = [&](int xi) -> ll {
            return dp[i - 1][1] + abs(xi - x[i - 1].front()) + x[i].back() - x[i].front();
        };
        auto dis0 = [&](int xi) -> ll {
            return dp[i - 1][0] + abs(xi - x[i - 1].back()) + x[i].back() - x[i].front();
        };

        dp[i][0] = min(dis0(x[i].front()), dis1(x[i].front()));
        dp[i][1] = min(dis0(x[i].back()), dis1(x[i].back()));
    }

    cout << ans + min(dp[len - 1][0], dp[len - 1][1]) << '\n';
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
//https://codeforces.com/problemset/problem/2156/D

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
    int n; cin >> n;

    vector<bool> vis(n + 1);
    vector<bool> ans(n + 1);

    int upbd = 0, tmp = n;
    while (tmp) {
        ++upbd;
        tmp >>= 1;
    }

    vector<vector<int>> num(2);
    int cnt[2];

    auto cal = [&](int pos) -> void {
        cnt[0] = cnt[1] = 0;
        num[0].clear();
        num[1].clear();

        for (int i=1 ; i<=n ; ++i) {
            if (!ans[i]) {
                num[(i >> pos) & 1].push_back(i);
            }
        }
    };

    for (int p = 0 ; p<upbd ; ++p) {
        cal(p);
        vector<vector<int>> idx(2);

        for (int i=1 ; i<n ; ++i) {
            if (vis[i]) continue;

            cout << "? " << i << ' ' << (1 << p) << endl;
            cin >> tmp;
            
            ++cnt[tmp];
            idx[tmp].push_back(i);
        }

        if (cnt[1] < num[1].size()) {
            for (auto& x : num[0])
                ans[x] = 1;
            for (auto& x : idx[0])
                vis[x] = 1;
        }
        else {
            for (auto& x : num[1])
                ans[x] = 1;
            for (auto& x : idx[1])
                vis[x] = 1;
        }
    }

    for (int i=1 ; i<=n ; ++i) {
        if (ans[i] == 0) {
            cout << "! " << i << endl;
            return;
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
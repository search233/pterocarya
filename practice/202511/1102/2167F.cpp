//https://codeforces.com/problemset/problem/2167/F

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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> e(n + 1);

    for (int i=1 ; i<n ; ++i) {
        int u, v;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    ll ans = 0;

    vector<int> sz(n + 1);
    auto dfs = [&](auto& dfs, int u, int fa) -> void {
        sz[u] = 1;

        for (auto& v : e[u]) {
            if (v == fa) continue;

            dfs(dfs, v, u);
            sz[u] += sz[v];
        }

        if (sz[u] >= k) ++ans;
    };

    dfs(dfs, 1, -1);

    auto cgrt = [&](int s1, int s2) -> int {
        int tmp = sz[s2];
        int s = sz[s1];

        sz[s1] -= sz[s2];
        sz[s2] = s;

        int ans = 0;
        if (sz[s1] >= k && tmp < k) ans = 1;
        else if (sz[s1] < k && tmp >= k) ans = -1;  

        return ans;
    };

    auto dfs1 = [&](auto& dfs1, int u, int fa, int sum) -> void {
        for (auto& v : e[u]) {
            if (v == fa) continue;

            sum += cgrt(u, v);
            ans += sum;

            // cout << v << ' ' << sum << ' ' << sz[u] << ' ' <<  sz[v] << '\n';

            // ans += cal(v);
            
            dfs1(dfs1, v, u, sum);
            
            sum += cgrt(v, u);
        }
    };

    dfs1(dfs1, 1, -1, ans);

    cout << ans << '\n';
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

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
 auto cal = [&](int r) -> int {
    int ans = 0;

    queue<int> qu;
    if (sz[r] >= k) {
        qu.push(r);
    }

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        ++ans;            

        for (auto& v : e[u]) {
            if (sz[v] >= k) {
                qu.push(v);
            }
        }
    }

    return ans;
};
*/
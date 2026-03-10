//https://codeforces.com/problemset/problem/2192/D

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
    int n; cin >> n;
    vector<ll> val(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }

    vector ee(n + 1, vector<int>());

    for (int i = 1; i < n ; ++i) {
        int u, v; cin >> u >> v;
        ee[u].push_back(v);
        ee[v].push_back(u);
    }

    vector e(n + 1, vector<int> ());
    vector<ll> cost(n + 1), sum(n + 1);
    vector<ll> d(n + 1), mxd(n + 1);

    auto init = [&](auto& init, int u, int f) -> void {
        d[u] = mxd[u] = d[f] + 1;
        sum[u] = val[u];
        for (auto v : ee[u]) {
            if (v != f) {
                e[u].push_back(v);
                init(init, v, u);
                mxd[u] = max(mxd[u], mxd[v]);
                sum[u] += sum[v];
                cost[u] += cost[v] + sum[v];
            }
        }
    };
    
    init(init, 1, 0);
    // for (int i = 1; i <= n; ++i) {
    //     cout << cost[i] << ' ' << sum[i] << '\n';
    // }

    vector<ll> ans(n + 1);

    auto dfs = [&](auto& dfs, int u) -> void {
        for (auto v : e[u]) {
            dfs(dfs, v);
        }

        int sz = e[u].size();
        if (sz == 0) {
            ans[u] = cost[u];
            return; 
        }
        if (sz == 1) {
           ans[u] = ans[e[u][0]] + cost[u] - cost[e[u][0]];
           return;
        }

        vector<ll> dl(sz), dr(sz);
        
        dl[0] = mxd[e[u][0]];
        for (int i = 1; i < sz; ++i) {
            dl[i] = max(dl[i - 1], mxd[e[u][i]]);
        }
        dr[sz - 1] = mxd[e[u][sz - 1]];
        for (int i = sz - 2; i >= 0; --i) {
            dr[i] = max(dr[i + 1], mxd[e[u][i]]);
        }
        
        for (int i = 0; i < sz; ++i) {
            int v  = e[u][i];
            ll mx = 0;
            if (i == 0) {
                mx = dr[1];
            }
            else if (i == sz - 1) {
                mx = dl[sz - 2];
            }
            else {
                mx = max(dl[i - 1], dr[i + 1]);
            }
            ans[u] = max(ans[u], cost[u] + sum[v] * (mx - d[u]));
            ans[u] = max(ans[u], cost[u] + ans[v] - cost[v]);
        }
    };
    dfs(dfs, 1);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
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
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░ 

*/

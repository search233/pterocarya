#include <bits/stdc++.h>
#include <cassert>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> d(n + 1);
    vector e(n + 1, vector<arr2>());

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        ++d[u];
        ++d[v];
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }

    vector<int> to(n + 1);
    for (int i = 1; i <= n; ++i) {
        to[i] = i;
    }
    for (int i = 1; i <= k; ++i) {
        int u, v;  cin >> u >> v;
        to[u] = v;
        to[v] = u;
    }

    vector<int> odd;
    for (int i = 1; i <= n; ++i) {
        if (to[i] != i) {
            if (d[i] < d[to[i]]) {
                // cout << d[to[i]] - d[i] << '\n';
                for (int j = 0; j < (d[to[i]] - d[i]); ++j) {
                    odd.push_back(to[i]);
                }
            }
        }
        else {
            if (d[i] & 1) {
                odd.push_back(i);
            }
        }
    }

    if (odd.size() > 2 || odd.size() == 1) {
        cout << "-1\n";
        return;
    }

    int s = -1;
    if (odd.size()) {
        s = odd.front();
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (d[i]) {
                s = i;
                break;
            }
        }
    }

    assert(s != -1);

    vector<bool> vis(m + 1);
    vector<arr2> path;
    auto dfs = [&](auto&& dfs, int u) -> void {
        while (!e[u].empty()) {
            auto [v, id] = e[u].back();
            e[u].pop_back();

            if (vis[id]) continue;
            vis[id] = 1;

            cout << u << ' ' << v << '\n';

            dfs(dfs, to[v]);
            path.push_back({u, v});
        }
    };

    dfs(dfs, s);

    reverse(path.begin(), path.end());

    int cnt = 0;
    vector<int> ans;
    for (auto [u, v] : path) {
        if (ans.empty()) {
            ans.push_back(u);
            ans.push_back(v);
        }
        else if (ans.back() != u) {
            ++cnt;
            ans.push_back(u);
            ans.push_back(v);
        }
        else {
            ans.push_back(v);
        }
    }

    // cout << ans.size() << ' ' << cnt << '\n';
    if (ans.size() - 1 - cnt != m) {
        cout << "-1\n";
        return;
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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
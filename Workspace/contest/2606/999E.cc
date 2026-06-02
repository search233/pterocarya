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
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> vis(n + 1);
    vector e(n + 1, vector<int>());

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }

    stack<int> stk;
    auto dfs1 = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        for (auto v : e[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
        stk.push(u);
    };

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs1(i);
    }

    vis.assign(n + 1, 0);

    auto dfs2 = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        for (auto v : e[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
    };

    dfs2(s);

    int ans = 0;
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();

        if (!vis[u]) {
            ++ans;
            dfs2(u);
        }
    }

    cout << ans << '\n';
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
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░
*/
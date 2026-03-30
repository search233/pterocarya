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

    vector e(n + 1, vector<int>());

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 2) {
            s = i;
            break;
        }
    }
    if (!s) {
        cout << "NO\n";
        return;
    }

    int u = e[s][0];
    int v = e[s][1];

    auto dfs = [&](auto&& dfs, int u, int f, int tag) -> void {
        for (auto v : e[u]) {
            if (v != f) {
                dfs(dfs, v, u, tag ^ 1);
            }
        }
        if (tag & 1) e[u].clear();
    };
    e[s].clear();
    e[s].push_back(u);
    dfs(dfs, u, s, 1);
    dfs(dfs, v, s, 0);

    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        for (auto v : e[i]) {
            cout << i << ' ' << v << '\n';
        }
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
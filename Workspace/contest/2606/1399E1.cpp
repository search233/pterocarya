#include <bits/stdc++.h>
#include <cassert>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<ll, 2>;
using arr3 = array<ll, 3>;
const double PI = acos(-1.0);

void solve() {
    ll n, s; 
    cin >> n >> s;

    vector e(n + 1, vector<arr2>());

    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;

        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    ll sum = 0;
    vector<int> sz(n + 1, 0);
    priority_queue<arr3> qu;
    auto dfs = [&](this auto&& dfs, int u, int f) -> void {
        if (e[u].size() == 1 && u != 1) {
            sz[u] = 1;
        }
        for (auto [v, w] : e[u]) {
            if (v == f) continue;
            dfs(v, u);
            sz[u] += sz[v];
            qu.push({(w + 1) / 2 * sz[v], w, sz[v]});
            sum += w * sz[v];
        }
    };

    dfs(1, 0);

    int cnt = 0;
    while (sum > s) {
        auto [ssum, w, fac] = qu.top();
        qu.pop();
 
        sum -= ssum;
        w >>= 1;

        qu.push({(w + 1) / 2 * fac, w, fac});
        ++cnt;
    }

    cout << cnt << '\n';
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
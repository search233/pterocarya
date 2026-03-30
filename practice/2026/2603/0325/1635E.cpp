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
    int n, m; cin >> n >> m;
    vector<arr3> E;
    vector e(n + 1, vector<int>());

    for (int i = 1; i <= m; ++i) {
        int t, u, v;
        cin >> t  >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
        E.push_back({t, u, v});
    }

    vector<int> c(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (c[i] != -1) continue;
        queue<int> qu;
        qu.push(i);
        c[i] = 0;

        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();

            for (auto v : e[u]) {
                if (c[v] == -1) {
                    c[v] = c[u] ^ 1;
                    qu.push(v);
                }
                else if(c[v] == c[u]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    vector<int> sz(n + 1);
    for (auto [t, u, v] : E) {
        // t = 1 :  0 -> 1
        // t = 2 ~ 0 :  1 -> 0
        t &= 1;
        if (t == c[u]) { 
            swap(u, v);
        }
        e[u].push_back(v);
        ++sz[v];
    }

    vector<int> vec;
    for (int i = 1;  i <= n; ++i) {
        if (sz[i] == 0) {
            vec.push_back(i);
        }
        // cout << sz[i] << " \n"[i == n];
    }

    for (int i = 0; i < vec.size(); ++i) {
        int u = vec[i];
        // cout <<"\n u =" << u << '\n';
        for (auto v : e[u]) {
            // cout << v << ' ';
            --sz[v];
            if (sz[v] == 0) {
                vec.push_back(v);
            }
        }
    }

    if (vec.size() != n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<arr2> res(n + 1);
    for (int i = 0; i < n; ++i) {
        int u = vec[i];

        if (c[u] == 0) {
            res[u] = {0, i};
        }
        else {
            res[u] = {1, i};
        }
    }

    for (int i = 1; i <= n; ++i) {
        auto [ori, p] = res[i];
        cout << "LR"[ori] << " " << p << '\n';
    }
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
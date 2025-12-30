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
    int m; cin >> m;

    map<int, int> mp;
    vector<int> a;
    vector<string> res(1);

    vector array(m + 1, vector<int>());

    for (int i = 1; i <= m; ++i) {
        int n; cin >> n;
        res.push_back(string(n, ' '));
        for (int j = 1; j <= n; ++j) {
            int num; cin >> num;
            array[i].push_back(num);
            a.push_back(num);
            ++mp[num];
        }
    }

    for (auto [num, cnt] : mp) {
        if (cnt & 1) {
            cout << "NO";
            return;
        }
    }

    ranges::sort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    unordered_map<int, int> id;
    for (int i = 0; i < a.size(); ++i) {
        id[a[i]] = i + m + 1;
    }

    vector e(m + 1 + a.size(), vector<arr2>());
    for (int i = 1; i <= m; ++i) {
        int u = i;

        for (auto x : array[u]) {
            int v = id[x];

            e[u].push_back({v, (int)e[v].size()});
            e[v].push_back({u, (int)e[u].size() - 1});
        }
    }

    vector<int> pos(m + 1 + a.size());
    
    auto dfs = [&](auto&& dfs, int u) -> void {

        while (pos[u] < e[u].size()) {
            auto [v, p] = e[u][pos[u]];

            if (v == -1) {
                ++pos[u];
                continue;
            }

            e[u][pos[u]][0] = -1;
            e[v][p][0] = -1;

            if (u <= m) {
                res[u][pos[u]] = 'L';
            }
            else {
                res[v][p] = 'R';
            }

            ++pos[u];
            dfs(dfs, v);    
        }
    };


    cout << "YES\n";
    for (int i = 1; i <= m; ++i) {
        dfs(dfs, i);
        cout << res[i] <<  '\n';
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
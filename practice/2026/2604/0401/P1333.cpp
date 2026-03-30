#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arrs2 = array<string, 2>;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void solve() {
    string s1, s2;

    vector<string> vec;
    vector<arrs2> E;

    while (cin >> s1 >> s2) {
        vec.push_back(s1);
        vec.push_back(s2);
        E.push_back({s1, s2});
    }
    int n = E.size();

    ranges::sort(vec);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    unordered_map<string, int> id;
    
    int m = vec.size();
    // 1 - n
    for (int i = 0; i < m; ++i) {
        id[vec[i]] = i + 1;
    }
    
    int cnt = 0;
    vector e(m + 1, vector<arr2>());
    for (auto [ss1, ss2] : E) {
        int u = id[ss1];
        int v = id[ss2];
        e[u].push_back({v, cnt});
        e[v].push_back({u, cnt});
        ++cnt;
    }

    vector<int> deg[2];
    for (int i = 1; i <= m; ++i) {
        if (e[i].size() == 0) continue;
        deg[e[i].size() & 1].push_back(i);
    }

    int s = -1;
    if (deg[1].size() != 0 && deg[1].size() != 2) {
        cout << "Impossible";
        return;
    }
    else if (deg[1].size() == 2) {
        s = deg[1][0];
    }
    else if (!deg[0].empty()) {
        s = deg[0][0];
    }

    vector<int> res;
    vector<int> used(cnt);

    auto dfs = [&](auto&& dfs, int u) -> void {
        while (!e[u].empty()) {
            auto [v, iid] = e[u].back();
            e[u].pop_back();

            if (used[iid]) continue;

            used[iid] = 1;
            dfs(dfs, v);
        }
        res.push_back(u);
    };

    dfs(dfs, s);

    if (res.size() != n + 1) {
        cout << "Impossible";
    }
    else {
        cout << "Possible";
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
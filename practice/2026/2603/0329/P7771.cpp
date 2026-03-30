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
    int n, m;
    cin >> n >> m;

    vector<arr2> cnt(n + 1); // cnt[i][0] ch
    vector e(n + 1, vector<int>());

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        ++cnt[u][0];
        ++cnt[v][1];
    }

    int s = 0, t = 0;
    for (int i = 1; i <= n; ++i) {
        ranges::sort(e[i], greater<int>());
        int dif = cnt[i][0] - cnt[i][1];

        if (dif == 1) {
            if (s) {
                cout << "No\n";
                return;
            }
            s = i;
        }
        else if (dif == -1) {
            if (t) {
                cout << "No\n";
                return;
            }
            t = i;
        }
        else if (dif) {
            cout << "No\n";
            return;
        } 
    }

    if (s == 0) s = 1;
    
    vector<int> res;
    auto dfs = [&](auto&& dfs, int u) -> void {
        while (!e[u].empty()) {
            int v = e[u].back();
            e[u].pop_back();
            dfs(dfs, v);
        }
        res.push_back(u);
    };
    dfs(dfs, s);

    reverse(res.begin(), res.end());
    for (auto i : res) {
        cout << i << ' ';
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
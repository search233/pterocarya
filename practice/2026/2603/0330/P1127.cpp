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

    vector<string> vec(n);
    vector<arr2> cnt(n + 26);
    vector e(n + 27, vector<int>());

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];

        int u = vec[i][0] - 'a';
        int v = i + 26;
        int w = vec[i].back() - 'a';

        e[u].push_back(v);
        ++cnt[u][0];
        ++cnt[v][1];

        e[v].push_back(w);
        ++cnt[v][0];
        ++cnt[w][1];
    }

    // 0 - 25  26 - 25 + n
    vector<int> p[3];
    for (int i = 0; i < 26; ++i) {
        ranges::sort(e[i], 
            [&](int a, int b) -> bool {
                return vec[a - 26] > vec[b - 26];
            });

        int dif = cnt[i][0] - cnt[i][1];

        if (dif > 1 || dif < -1) {
            cout << "***";
            return;
        }

        if (cnt[i][0] || cnt[i][1]) {
            p[dif + 1].push_back(i);
        }        
    }

    int s = 0;
    if (p[0].size() == 1 && p[2].size() == 1) {
        s = p[2][0];
    }
    else if (p[0].size() + p[2].size() == 0 && p[1].size()) {
        s = p[1][0];
    }
    else {
        cout << "***";
        return;
    }

    vector<int> res;
    auto dfs = [&](auto&& dfs, int u) -> void {
        while (!e[u].empty()) {
            int v = e[u].back();
            e[u].pop_back();
            dfs(dfs, v);            
        }
        if (u > 25) {
            res.push_back(u - 26);
        }
    };

    dfs(dfs, s);
    
    if (res.size() != n) {
        cout << "***";
        return;
    }

    reverse(res.begin(), res.end());
    cout << vec[res[0]];
    for (int i = 1; i < n; ++i) {
        cout << '.'  << vec[res[i]];
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
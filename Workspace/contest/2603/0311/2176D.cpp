//https://codeforces.com/problemset/problem/2176/D

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);
const ll MOD = 998244353;

ll mod(ll num) {
    num %= MOD;
    if (num < 0) num += MOD;
    return num;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> val(n + 1);

    for (int i = 1; i <= n ;++i) {
        cin >> val[i];
    }

    vector<arr2> e;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        e.push_back({u, v});
    }

    ranges::sort(e, [&](arr2 x, arr2 y) {
        return val[x[1]] < val[y[1]];   
    });

    ll ans = 0;
    vector<unordered_map<ll, ll>> mp(n + 1);
    for (auto [v, w] : e) {
        auto it = mp[v].find(val[w] - val[v]);
        int tmp = 1;
        if (it != mp[v].end()) {
            tmp = mod(tmp + it->second);
        }
        mp[w][val[v]] = mod(mp[w][val[v]] + tmp);
        ans = mod(ans + tmp);
    }

    cout << ans << '\n';
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

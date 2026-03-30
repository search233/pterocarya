#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

const ll MOD = 1e9 + 7;

int fac[(int)2e5 + 10];

ll mod(ll num) {
    num %= MOD;
    if (num < 0) {
        num += MOD;
    }
    return num;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < (int)(2e5 + 10); ++i) {
        fac[i] = mod(1ll * fac[i - 1] * i);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector e(n + 1, vector<int>());

    vector<int> cnt(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
        ++cnt[u];
        ++cnt[v];
    }

    int f = 0;
    vector<int> sz(n + 1);
    vector<bool> vis(n + 1);

    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
        vis[u] = 1;
        sz[u] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;

            if (vis[v] == 1) {
                f = 1;
                return;
            }

            dfs(dfs, v, u);
            sz[u] += sz[v];
        }
    };

    dfs(dfs, 1, -1);

    if (f) {
        cout << "0\n";
        return;
    }

    int ans = 1;
    int ccnt = 0;

    for (int i = 1; i <= n; ++i) {
        cnt.assign(2, 0);

        for (auto v : e[i]) {
            int size = sz[v];
            if (sz[v] > sz[i]) {
                size = n - sz[i];
            }

            if (size == 1) ++cnt[0];
            else ++cnt[1];
        }

        if (cnt[1] > 2) {
            ans = 0;
            break;
        }

        if (cnt[1] == 0) {
            cout << mod(fac[n - 1] * 2ll) << '\n';
            return;
        }

        ans = mod(1ll * ans * fac[cnt[0]]);
    }

    cout << mod(ans * 4ll) << '\n';
}

int main() {
    
    __BUFF__

    init();
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
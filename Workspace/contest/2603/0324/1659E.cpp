//https://codeforces.com/contest/1659/problem/E
#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

class DSU {
private:
    int n;
    vector<int> fa, sz;

    void init(int n) {
        this->n = n;
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
        even.resize(n + 1);
    }

public:
    vector<bool> even;

    DSU(int n) {
        init(n);
    }

    int find(int x) {
        if (fa[x] != x)
            fa[x] = find(fa[x]);
        return fa[x];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);

        fa[v] = u;
        sz[u] += sz[v];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<DSU> dsu(30, DSU(n));
    vector<arr3> edge;

    vector e(n + 1, vector<arr2>());
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        edge.push_back({u, v, w});

        for (int i = 0; i < 30; ++i) {
            if ((w >> i) & 1) {
                dsu[i].merge(u, v);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        auto [u, v, w] = edge[i];
        if (w & 1) continue;
        for (int j = 0; j < 30; ++j) {
            dsu[j].even[dsu[j].find(u)] = 1;
            dsu[j].even[dsu[j].find(v)] = 1;
        }
    }

    int q; cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        int a = 0, b = 0;
        for (int i = 0; i < 30; ++i) {
            a = dsu[i].same(u, v);
            if (a) break;
        } 
        if (a) {
            cout << "0\n";
            continue;
        }

        for (int i = 1; i < 30; ++i) {
            b = dsu[i].even[dsu[i].find(u)];
            if (b) break;
        }
        if (b) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
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
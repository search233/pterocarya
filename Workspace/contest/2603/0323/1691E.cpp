//https://codeforces.com/contest/1691/problem/E

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr5 = array<int, 5>;
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
    }

public:
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
    int n; cin >> n;
    vector<arr5> segs;// c, pos, r, id, typ

    for (int i = 1; i <= n; ++i) {
        int c, l, r;
        cin >> c >> l >> r;
        segs.push_back({c, l, r, i, 0});
        segs.push_back({c, r, -1, i, 1});
    }

    ranges::sort(segs, []
    (arr5 a, arr5 b) -> bool {
        if (a[1] != b[1]) 
            return a[1] < b[1];
        
        return a[4] < b[4];
    });

    DSU dsu(n);
    set<arr2> st[2];

    for (auto it : segs) {
        auto [c, p, r, id, ty] = it;

        if (ty == 1) {
            st[c].erase({p, id});
            continue;
        }

        st[c].insert({r, id});

        while (st[c ^ 1].size() > 1) {
            dsu.merge(id, (*st[c ^ 1].begin())[1]);
            st[c ^ 1].erase(st[c ^ 1].begin());
        }

        if (!st[c ^ 1].empty()) {
            dsu.merge(id, (*st[c ^ 1].begin())[1]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dsu.find(i) == i) ++ans;
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
//https://ac.nowcoder.com/acm/contest/127263/C

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
        fa[v] = u;
        sz[u] += sz[v];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n; cin >> n;

    vector<int> p(n), id(n), d(n);
    for (auto& i : p) cin >> i;
    for (auto& i : id) cin >> i;
    for (auto& i : d) cin >> i;

    DSU dsu(n);

    for (int i = 0; i < n; ++i) {
        dsu.merge(p[i], d[i]);
    }

    for (int i = 1; i <= n; ++i) {
        int f = dsu.find(i);
    }

    vector<int> vis(n + 1, 0);

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int f = dsu.find(p[id[i] - 1]);

        // cout << id[i] << ' ' << p[id[i] - 1] << '\n';
        if (vis[f] == 0) {
            vis[f] = 1;
            sum += dsu.size(f);
        }

        cout << sum << " \n"[i == n - 1];
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
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │              
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐    
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │    
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
│Ctrl │Win │Alt │         Space         │Alt │ Fn │Menu│Ctrl│ │ ← │ ↓ │ → │
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

*/
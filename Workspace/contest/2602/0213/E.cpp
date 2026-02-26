//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

struct DSU{
	int n;
	vector<int>fa, sz;

	DSU(int n){
		init(n);
	}

	void init(int n){
		this -> n = n;
		fa.assign(n + 5, 0);
		sz.assign(n + 5, 1);
		for(int i = 0; i <= n; i++)fa[i] = i;
	}

	int find(int k){
		return k == fa[k] ? k : fa[k] = find(fa[k]);
	}

	bool same(int u, int v){
		return find(u) == find(v);
	}

	bool un(int u, int v){
		u = find(u); v = find(v);
		if(u == v)return false;
		sz[u] += sz[v];
		fa[v] = u;
        return true;
	}

	int size(int x){
		return sz[find(x)];
	}

};


void solve() {
    int n, m, x, d;
    cin >> n >> m >> x >> d;

    vector<int> h(n + 1);
    vector<arr2> vec;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        vec.push_back({h[i], i});
    }

    vector<arr3> e;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;        
        e.push_back({u, v, min(h[u], h[v])});
    }

    ranges::sort(e, []
    (arr3 a, arr3 b) -> bool {
        return a[2] > b[2];
    });
    ranges::sort(vec);

    vector<int> H(x);
    for (int i = 0; i < x; ++i) {
        cin >> H[i];
    }

    int p = 0;
    DSU dsu(n);
    set<int> f;
    int cnt = 0;
    stack<int> ans;

    for (int i = x - 1; i >= 0; --i) {
        while (vec.size() && vec.back()[0] > H[i]) {
            if (d == 1) ++cnt;
            vec.pop_back();
        }
        while (p < e.size() && e[p][2] > H[i]) {
            if (!dsu.same(e[p][0], e[p][1])) {
                if (dsu.size(e[p][1]) >= d) --cnt;
                if (dsu.size(e[p][0]) >= d) --cnt;
                dsu.un(e[p][0], e[p][1]);
                if (dsu.size(e[p][1]) >= d) ++cnt;
            }
            ++p;
        }
        ans.push(cnt);
    }

    while (!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
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
│ Tab │ Q │ W │ st │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│
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

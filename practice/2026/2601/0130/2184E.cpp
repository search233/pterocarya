//https://codeforces.com/problemset/problem/2184/E

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

	void un(int u, int v){
		u = find(u); v = find(v);
		if(u == v)return ;
		sz[u] += sz[v];
		fa[v] = u;
	}


	int size(int x){
		return sz[find(x)];
	}

    ll cal(int x) {
        ll len = size(x);
        return len * (len - 1) / 2;
    }
};

void solve() {
    int n; cin >> n;

    vector<int> p(n);
    vector<vector<int>> d(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];

        if (i) {
            d[abs(p[i] - p[i - 1])].push_back(i);
        }
    }

    DSU dsu(n);

    ll cur = 0;
    stack<ll> ans;

    for (int i = n - 1; i >= 1; --i) {
        for (auto j : d[i]) {
            // j-1 ___ j
            cur -= dsu.cal(j - 1);
            cur -= dsu.cal(j);

            dsu.un(j - 1, j);

            cur += dsu.cal(j);
        }

        ans.push(cur);
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';

        ans.pop();
    }
    cout << '\n';
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
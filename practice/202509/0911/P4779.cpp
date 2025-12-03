//https://www.luogu.com.cn/problem/P4779

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const int INF = INT_MAX;
const double PI = acos(-1.0);

void solve() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<arr2>> e(n + 1);

    for (int i=0 ; i<m ; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    vector<int> dis(n + 1, INF);
    vector<bool> vis(n + 1, 0);

    auto dij = [&](int s) -> void {
        priority_queue<arr2, vector<arr2>, greater<arr2>> qu;
        qu.push({0, s});
        dis[s] = 0;

        while (!qu.empty()) {
            int u = qu.top()[1];
            qu.pop();

            if (vis[u]) continue;
            vis[u] = 1;

            for (auto [v, w] : e[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    qu.push({dis[v], v});
                }
            }
        }
    };

    dij(s);

    for (int i=1 ; i<=n ; ++i) {
        cout << dis[i] << ' ';
    }
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    // cin >> _;

    while (_--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*
struct Dij{
	int n;
	vector<vector<pll>>e;
	vector<ll>dis;
	vector<bool>vis;

	Dij(int n){
		this -> n = n;
		e.resize(n+2);
		dis.assign(n+2, INF);
		vis.assign(n+2, 0);
		for(int i = 1; i <= n; i++)e[i].clear();
	}

	void di(int s){
		priority_queue<pll, vector<pll>, greater<pll>>q;
		dis[s] = 0;
		q.push(pll{0, s});
		while(!q.empty()){
			auto it = q.top(); q.pop();
			int u = it.second;
			if(vis[u])continue;
			vis[u] = 1;
			for(auto [v, w] : e[u]){
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					q.push(pll{dis[v], v});
				}
			}
		}
	}
};

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
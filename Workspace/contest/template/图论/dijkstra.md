```cpp

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


```
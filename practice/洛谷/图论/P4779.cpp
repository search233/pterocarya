//P4779(dijkstra) 

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

int n, m, s;
ll dist[100005];
vector<pii> graph[100005];


void dijkstra(){
	for(int i=1 ; i<=n ; ++i) dist[i]=LLONG_MAX;
	dist[s] = 0;
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0,s});
	
	while(!pq.empty()){
		ll dis = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		
		if(dis > dist[u]) continue;
		for(int i=0 ; i<(int)graph[u].size() ; ++i){
			auto edge = graph[u][i];
			int v = edge.second;
			ll w = edge.first;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u]  + w;
				pq.push({dist[v],v});
			}
		}
	}
} 
int main()
{
	cin >> n >> m >> s;
	for(int i=0 ; i<m ; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({w,v});
	}
	
	dijkstra();
	
	for(int i=1 ; i<=n ; ++i) cout << dist[i] << ' ';
	
	return 0;
}

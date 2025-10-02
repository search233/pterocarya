//P1137

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dp[100005];
int in[200005];
vector<int> graph[100005];

int main()
{
	int n, m; cin >> n >> m;
	for(int i=0 ; i<m ; ++i){
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		++in[v];
	}
	
	queue<int> q;
	 
	for(int i=1 ; i<=n ; ++i){
		if(!in[i]){
			q.push(i);
			dp[i] = 1;
		}
	}
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i=0 ; i<(int)graph[u].size() ; ++i){
			int v = graph[u][i];
			dp[v] = max(dp[u]+1, dp[v]);
			--in[v];
			if(in[v]==0) q.push(v);
		}
	}
	
	for(int i=1 ; i<=n ; ++i){
		cout << dp[i] << '\n';
	}
	
	return 0;
}

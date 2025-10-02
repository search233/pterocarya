//1004

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int p, d;
};

vector<int> graph[105];

int main()
{
	int ans[105]={0};
	int n, m; cin >> n >> m;
	
	while(m--){
		int id, k; cin >> id >> k;
		
		while(k--){
			int v; cin >> v;
			graph[id].push_back(v);
		}
	}
	
	
	queue<node> qu;
	qu.push({1,0});
	int max_d;
	
	while(!qu.empty()){
		auto it = qu.front();
		qu.pop();
		
		int u = it.p;
		int dep = it.d;
		
		if(graph[u].size()==0)	++ans[dep];
		
		for(int v : graph[u]){
			qu.push({v, dep+1});
			max_d=dep+1;
		}
	}
	
	for(int i=0 ; i<=max_d ; ++i){
		if(i==0) cout << ans[i];
		else cout << ' ' << ans[i];
	}
	
	return 0;
}

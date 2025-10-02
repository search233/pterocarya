//P8893

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int in[500000];
int n, k, p;
queue<pair<int,int>> q;
vector<int> graph[500000];

int main()
{
	cin >> n >> k >> p;
	for(int i=0 ; i<p ; ++i){
		int num; cin >> num;
		q.push({num,0});
		if(num==k){
			cout << 0;
			return 0; 
		}
	}
	int r; cin >> r;
	for(int i=0 ; i<r ; ++i){
		int v, m; cin >> v >> m;
		in[v] = m;
		for(int j=0 ; j<m ; ++j){
			int u; cin >> u;
			graph[u].push_back(v);
		}
	}
	
	while(!q.empty()){
		auto it = q.front();
		++it.second; 
		q.pop();
		for(int i=0 ; i<(int)graph[it.first].size() ; ++i){
			--in[graph[it.first][i]];
			
			if(!in[graph[it.first][i]]){
				q.push({graph[it.first][i],it.second});
				
				if(graph[it.first][i]==k){
					cout << it.second;
					return 0;
				}
			}
		}
	}
	
	cout << -1;
	return 0;
}

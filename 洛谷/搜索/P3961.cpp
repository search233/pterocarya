//P3961

#include <iostream>
#include <vector>

using namespace std;

int n, m, res[100010];
vector<int> list[100010];

void dfs(int i, int num){
	if(res[i]) return;
	res[i] = num;
	for(int j=0 ; j<(int)list[i].size() ; ++j){
		dfs(list[i][j], num);
	}
}

int main()
{
	cin >> n >> m;
	for(int i=1 ; i<=m ; ++i){
		int u, v;
		cin >> u >> v;
		list[v].push_back(u);
	}
	
	for(int i=n ; i>0 ; --i) dfs(i,i);
	
	for(int i=1 ; i<=n ; ++i){
		cout << res[i] << ' ';
	}
	
	return 0;
}

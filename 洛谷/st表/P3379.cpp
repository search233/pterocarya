//P3379

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int Log = 20;
const int maxn = 500010;

vector<int> tree[maxn]; //邻接表存树,需要建双向边 
int depth[maxn];		//记录深度 
int up[maxn][Log];		//up[u][k] 表示节点 u 的 2^k 级祖先 


void dfs(int u, int fa){
	depth[u] = depth[fa] + 1; 
	up[u][0] = fa;
	for(int i=1 ; i<Log ; ++i){
		up[u][i] = up[up[u][i-1]][i-1];
	}
	for(int v : tree[u]){
		if(v!=fa){
			dfs(v, u);
		}
	}
}


int lca(int a, int b){
	if(depth[a]<depth[b]) swap(a,b);
	
	int dif = depth[a] - depth[b];
	for(int i=0 ; i<Log ; ++i){
		if(dif & (1<<i)){
			a = up[a][i];
		}
	}
	
	if(a==b) return a;
	
	for(int i=Log-1 ; i>=0 ; --i){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

 
int main()
{
	int x, y;
	int n, m, s;
	cin >> n >> m >> s;
	
	for(int i=1 ; i<n ; ++i){
		scanf("%d%d", &x, &y);
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(s, 0);
	
	for(int i=0 ; i<m ; ++i){
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x,y));
	}
	
	return 0;
}

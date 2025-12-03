//P1369

#include <iostream>
#include <algorithm>

using namespace std;

struct Edge{
	int u, v, w;
}edge[20005];

int fp[10005];
int n, m, s, t;

bool cmp(Edge a, Edge b){ return a.w < b.w; }

int find(int u){
	if(u==fp[u]) return fp[u];
	else return fp[u] = find(fp[u]);
}

int kruskal(){
	int ans;
	int rtu, rtv;
	for(int i=0 ; i<m ; ++i){
		rtu = find(edge[i].u);
		rtv = find(edge[i].v);
		if(rtu!=rtv){
			ans = edge[i].w;
			fp[rtu] = rtv;
		}
		if(find(s)==find(t))
			break;
	}
	return ans;
}


int main()
{
	cin >> n >> m >> s >> t;
	
	for(int i=1 ; i<=n ; ++i) fp[i]=i;
	
	for(int i=0 ; i<m ; ++i){
		cin >> edge[i].u;
		cin >> edge[i].v;
		cin >> edge[i].w;
	}
	
	sort(edge, edge+m, cmp);
	
	cout << kruskal();
	
	return 0;
}

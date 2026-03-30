//P1536

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int fp[1100];

int find(int u){
	if(u!=fp[u])
		fp[u] = find(fp[u]);
	return fp[u];
}


int main(){
	
	int j; cin >> j;
	while(j){
		n=j; 
		cin >> m;
		
		for(int i=1 ; i<=n ; ++i) fp[i]=i;
		
		int ans = 0;
		for(int i=0 ; i<m ; ++i){
			int u, v; cin >> u >> v;
			int rtu = find(u);
			int rtv = find(v);
			if(rtu!=rtv) fp[rtu]=rtv;
		}
		for(int i=1 ; i<=n ; ++i){
			if(fp[i]==i) ++ans;
		}
		cout << ans-1 << '\n';
		cin >> j;
	}
	
	return 0;
}

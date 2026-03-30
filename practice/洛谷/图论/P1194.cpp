//P1194

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct E{
	int u, v, w;
}edge[150000];

int fp[510];
int a, b;

int find(int u){
	if(u!=fp[u]) fp[u]=find(fp[u]);
	return fp[u];
}

bool cmp(E i,E j){ return i.w < j.w; }

int kruskal(){
	for(int i=1 ; i<=b ; ++i) fp[i]=i;
	
	int sum=a, cnt=0;
	for(int i=0 ; ; ++i){
		int rtu = find(edge[i].u);
		int rtv = find(edge[i].v);
	
		if(rtu!=rtv){
			sum += edge[i].w;
			fp[rtu] = rtv;
			++cnt;
		}
		
		if(cnt==b-1) break;
	}
	
	return sum;
}


int main()
{
	cin >> a >> b;
	int cnt=0;
	for(int i=0 ; i<b ; ++i){
		for(int j=0 ; j<b ; ++j){
			int n; cin >> n;
			
			if(i>j){
				edge[cnt].u = i+1;
				edge[cnt].v = j+1;
				if(n>a || !n) n=a;
				edge[cnt++].w = n;	
			}
		}
	}
	
	sort(edge, edge+cnt, cmp);
	
	cout << kruskal();
	
	return 0;
}

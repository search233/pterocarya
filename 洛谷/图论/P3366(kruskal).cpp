//P3366(kruskal)

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int f[5010];

struct line{
	int x, y, w;
}l[200010];


bool cmp(line a, line b){ return a.w < b.w; }

int find(int x){
	if(x==f[x]) return f[x];
	else return f[x] = find(f[x]);
}

int kruskal(){
	
	int ans=0, cnt=0;
	for(int i=0 ; i<m ; ++i){
		int rtx = find(l[i].x);
		int rty = find(l[i].y);
		if(rtx == rty) continue;
		else{
			++cnt;
			ans += l[i].w;
			f[rtx] = rty;
		}
		if(cnt==n-1) return ans;
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	
	for(int i=1 ; i<=n ; ++i) f[i]=i;
	
	for(int i=0 ; i<m ; ++i){
		cin >> l[i].x >> l[i].y >> l[i].w;		
	}
	
	sort(l, l+m, cmp);
	
	int ans=kruskal();
	if(ans) cout << ans;
	else cout << "orz";
	
	return 0;
}

//P1816

#include <iostream>

using namespace std;

int Log[100005];
int st[100005][20];

int main()
{
	int n, m; cin >> m >> n;
	for(int i=2 ; i<=m ; ++i)
		Log[i] = Log[i>>1]+1;
	
	for(int i=1 ; i<=m ; ++i)
		cin >> st[i][0];
	
	for(int j=1 ; j<=Log[m] ; ++j){
		for(int i=1 ; i<=m-(1<<j)+1 ; ++i)
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	}
	
	for(int i=0 ; i<n ; ++i){
		int x, y;
		cin >> x >> y;
		
		int s=Log[y-x+1];
		cout << min(st[x][s], st[y-(1<<s)+1][s]) << ' ';
	}
	
	return 0;
}

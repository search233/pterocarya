//P3865


#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int st[100010][20];
int lg[100010];

int main()
{
	cin >> n >> m;
	
	for(int i=2 ; i<=n ; ++i) lg[i] = lg[i>>1] +1;
	for(int i=1 ; i<=n ; ++i) scanf("%d", &st[i][0]);
	for(int j=1 ; j<=lg[n] ; ++j){
		for(int i=1 ; i<=n-(1<<j)+1 ; ++i){
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
	
	int x, y;
	for(int i=1 ; i<=m ; ++i){
		scanf("%d%d", &x, &y);
		int len = lg[y-x+1];
		printf("%d\n", max(st[x][len], st[y-(1<<len)+1][len]));
	}
	
	return 0;
}

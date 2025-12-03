//P1535(dfs)

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, m, t;
int r1, c1, r2, c2;
int me[110][100][20];
int map[110][110];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int dfs(int x, int y, int costTime){
	
	if(me[x][y][costTime]!=-1) return me[x][y][costTime];
	
	if(costTime>t || abs(x-r2)+abs(y-c2) > t-costTime){
		return me[x][y][costTime] = 0;
	}
	
	if(t==costTime){
		if(x==r2 && y==c2) return me[x][y][costTime] = 1;
		else return me[x][y][costTime] = 0;
	}
	
	int res=0;
	for(int i=0 ; i<4 ; ++i){
		int tx = x + dx[i];
		int ty = y + dy[i];
		
		if(map[tx][ty] || tx<1 || tx>n || ty<1 || ty>m) continue;
		res += dfs(tx, ty, costTime+1);
	}
	
	return me[x][y][costTime] = res;
}


int main()
{
	cin >> n >> m >> t;
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			char ch; cin >> ch;
			if(ch=='*') map[i][j] = 1;
		}
		getchar();
	}
	
	memset(me, -1, sizeof(me));
	
	cin >> r1 >> c1 >> r2 >> c2;
	
	cout << dfs(r1,c1,0);
	
	return 0;
}

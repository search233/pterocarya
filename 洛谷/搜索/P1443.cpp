//P1443

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, m;
int map[410][410];
int vis[410][410];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

void bfs(int x, int y){
	
	queue<pair<int, int>> qu;
	qu.push({x, y});
	
	while(!qu.empty()){
		auto cur = qu.front();
		qu.pop();
		
		for(int i=0 ; i<8 ; ++i){
			int tx = cur.first + dx[i];
			int ty = cur.second + dy[i];
			if(tx<1 || tx>n || ty<1 || ty>m) continue;
			if(!vis[tx][ty]){
				vis[tx][ty] = 1;
				map[tx][ty] = map[cur.first][cur.second]+1;
				qu.push({tx, ty});
			}
		}	
	}
	return; 
}


int main(){
	int x, y;
	cin >> n >> m >> x >> y;
	
	bfs(x, y);
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			if(!map[i][j]) map[i][j]=-1;
		}
	}
	map[x][y] = 0;
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			printf("%-5d", map[i][j]);
		}
		cout << '\n';
	}
	
	return 0;
}

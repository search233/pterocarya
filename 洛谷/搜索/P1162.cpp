//P1162

#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[40][40];
int dj[4] = {0,-1,0,1};
int di[4] = {-1,0,1,0};

int judge(int i, int j){
	int res = 1;
	if(i<1 || i>n) res = 0;
	else if(j<1 || j>n) res=0;
	else if(arr[i][j]) res=0;
	
	return res;
}

void bfs(int i, int j){
	queue<pair<int,int>> qu;
	qu.push({i,j});
	if(arr[i][j]==0){
		arr[i][j]=2;
		while(!qu.empty()){
			auto cur = qu.front();
			qu.pop();
			for(int k=0 ; k<4 ; ++k){
				int ti = cur.first+di[k];
				int tj = cur.second+dj[k];
				if(judge(ti,tj)){
					arr[ti][tj] = 2;
					qu.push({ti,tj});
				}
			}
		}	
	}
	
	return;
}

int main()
{
	cin >> n;
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j) 
			cin >> arr[i][j];
	}
	
	for(int i=1 ; i<=n ; ++i){
		bfs(i,1);
		bfs(i,n);
	}
	
	for(int j=1 ; j<=n ; ++j){
		bfs(1,j);
		bfs(n,j);
	}
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			if(arr[i][j]==2) arr[i][j]=0;
			else if(arr[i][j]==0) arr[i][j]=2;
		}
	}
		
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			cout << arr[i][j] << ' ';
		}
		cout << '\n'; 
	}
	
	return 0;
}

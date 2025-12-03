//P1216

#include <iostream>

using namespace std;

int graph[1005][1005];

int main()
{
	int r; cin >> r;
	int ans = 0;
	for(int i=1 ; i<=r ; ++i){
		for(int j=1 ; j<=r ; ++j){
			if(i<j) break;
			cin >> graph[i][j];
			graph[i][i] += graph[i-1][i-1];
			graph[i][0] += graph[i-1][0];
			
			if(j>0 && j<i)
				graph[i][j] += max(graph[i-1][j], graph[i-1][j-1]);

			if(i==r) ans = max(ans, graph[i][j]);
		}
	}
	
//	for(int i=1 ; i<=r ; ++i){
//		for(int j=1 ; j<=r ; ++j){
//			if(i<j) break;
//			cout << graph[i][j] << ' ';
//		}
//		cout << '\n';
//	}	
	
	cout << ans;
	
	return 0;
}

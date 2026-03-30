//P1681

#include <iostream>
#include <cstdio>

using namespace std;

int dp[1505][1505][2];
int map[1505][1505];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j)
			scanf("%d", &map[i][j]);
	}
	
	int ans=0;
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			if(map[i][j]==0){
				dp[i][j][0] = min(dp[i-1][j-1][0], min(dp[i-1][j][1], dp[i][j-1][1])) + 1;
				ans = max(ans, dp[i][j][0]);
			}else{
				dp[i][j][1] = min(dp[i-1][j-1][1], min(dp[i-1][j][0], dp[i][j-1][0])) + 1;
				ans = max(ans, dp[i][j][1]);
			}
		}
	}
	
	cout << ans;
	
	return 0;
}

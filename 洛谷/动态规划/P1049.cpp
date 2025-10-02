//P1049

#include <iostream>

using namespace std;

int w[40];
int dp[20005];

int main()
{
	int v, n; cin >> v >> n;
	for(int i=0 ; i<n ; ++i) cin >> w[i];
	
	for(int i=0 ; i<n ; ++i){
		for(int j=v ; j>=w[i] ; --j){
			dp[j] = max(dp[j], dp[j-w[i]]+w[i]);
		}
	}
	
	cout << v-dp[v];
	
	return 0;
}

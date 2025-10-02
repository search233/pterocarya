//P1586

#include <iostream>

using namespace std;

int maxn = 32768;
int dp[5][33000] = {{1}};

int main()
{
	for(int i=1 ; i*i<=maxn ; ++i){
		for(int j=i*i ; j<=maxn ; ++j){
			for(int k=1 ; k<=4 ; ++k){
				dp[k][j] += dp[k-1][j-i*i];
			}
		}
	}
	
	int t; cin >> t;
	
	for(int i=0 ; i<t ; ++i){
		int n; cin >> n;
		int sum=0;
		for(int j=1 ; j<=4 ; ++j)
			sum += dp[j][n];
		cout <<  sum << '\n';
	}
	
	return 0;
}

//P1833

#include <iostream>
#include <cstdio>

using namespace std;

struct map{
	int C, P, T;
}list[10005];

int dp[1005];

int main()
{
	int a1, a2, b1, b2;
	scanf("%d:%d", &a1, &a2);
	scanf("%d:%d", &b1, &b2);
	int n; cin >> n;
	int t=(b1-a1)*60+b2-a2;
	
	for(int i=1 ; i<=n ; ++i)
		scanf("%d %d %d", &list[i].T, &list[i].C, &list[i].P);
	
	
	for(int i=1 ; i<=n ; ++i){
		
		if(!list[i].P){
			for(int j=list[i].T ; j<=t ; ++j)
				dp[j] = max(dp[j], dp[j-list[i].T]+list[i].C); 
				
		}else{
			for(int j=1 ; j<=list[i].P ; ++j){
				for(int k=t ; k>=j*list[i].T ; --k){
					dp[k] = max(dp[k], dp[k-list[i].T]+list[i].C);
				}
			} 
		}
	}
	
	cout << dp[t];
	
	return 0;
}

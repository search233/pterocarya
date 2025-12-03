//P3383

#include <iostream>

using namespace std;

int list[100000010];
int prime[1000000];
int main()
{
	int n, q; cin >> n >> q;
	list[1]=1;
	int cnt = 0;
	for(int i=2 ; i<=n ; ++i){
		if(list[i]==0) prime[cnt++]=i;
		for(int j=0 ; j<cnt && i*prime[j]<=n ; ++j){
			list[i*prime[j]] = 1;
			if(i%prime[j]==0) break;
		}
	}
	
	for(int i=0 ; i<q ; ++i){
		int k; cin >> k;
		cout << prime[k-1] << '\n'; 
	}
	
	return 0;
}

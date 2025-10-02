//P2440

#include <iostream>
#define ll long long

using namespace std;

int a[100010];

int main(){

	int n, k; cin >> n >> k;
	for(int i=0 ; i<n ; ++i) cin >> a[i];
	
	ll l=0, r=1e8;
	
	while(l+1<r){
		ll mid = (l+r)/2, sum=0;
		for(int i=0 ; i<n ; ++i){
			sum += a[i] / mid;
		}
		if(sum>=k) l = mid;
		else r = mid;
	}
	
	cout << l;
	
	return 0;
}

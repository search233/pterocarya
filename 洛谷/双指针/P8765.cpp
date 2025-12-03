//P8775

#include <iostream>

using namespace std;

int main(){
	int n, x; cin >> n >> x;
	x=2*x;
	
	int h[n+1];
	for(int i=1 ; i<n ; ++i) cin >> h[i];
	
	int res=0;
	for(int i=1, j=0, sum=0; i<n ; ++i ){
		while(j<n && sum<x) sum += h[++j];
		res = max(res, j-i+1);
		sum -= h[i];
	}
	
	cout << res;

	return 0;
} 

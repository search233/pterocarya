//P8218

#include <iostream>
#include <vector>

using namespace std;

int arr[100010];

int main(){
	int n; cin >> n;
	
	for(int i=1 ; i<=n ; ++i){
		int t; cin >> t;
		arr[i] = t + arr[i-1];
	}
	
	int m; cin >> m;
	for(int i=0 ; i<m ; ++i){
		int l, r; cin >> l >> r;
		cout << arr[r]-arr[l-1] << '\n'; 
	}
	
	return 0;
}

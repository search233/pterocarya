//P2367

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, p; cin >> n >> p;
	vector<int> a(n+5,0);
	
	for(int i=1 ; i<=n ; ++i) cin >> a[i];
	for(int i=n ; i>1 ; --i) a[i] -= a[i-1];
	
	
	for(int i=0 ; i<p ; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		a[x] += z;
		a[y+1] -= z;
	}
	
	int res = a[1];
	for(int i=2 ; i<=n ; ++i){
		a[i] += a[i-1];
		res = min(res, a[i]);
	}
	
	cout << res;
	
	return 0;
}

//SP16487

#include <iostream>

using namespace std;

int a[10010];

int main()
{
	int t; cin >> t;
	
	for(int i=0 ; i<t ; ++i){
		
		int n, u;
		cin >> n >> u;
		fill(a, a+n+5, 0);
				
		for(int j=0 ; j<u ; ++j){
			int l, r, v;
			cin >> l >> r >> v;
			
			a[l] += v;
			a[r+1] -= v;
		}
		
		for(int j=1 ; j<n ; ++j) a[j] += a[j-1];
		
		int q; cin >> q;
		for(int j=0 ; j<q ; ++j){
			int num; cin >> num;
			cout << a[num] << '\n';
		}
	}
	
	return 0;
}

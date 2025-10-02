//P5788

#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n; cin >> n;
	int a[n], res[n];
	stack<int> s;
	
	for(int i=0 ; i<n ; ++i) cin >> a[i];
	
	for(int i=n-1 ; i>=0 ; --i){

		while(!s.empty() && a[i]>=a[s.top()]){
			s.pop();
		}
		res[i]= s.empty() ? 0 : s.top()+1;			
		s.push(i);	
	}
	
	for(int i=0 ; i<n ; ++i) cout << res[i] << ' ';
	
	return 0;
}

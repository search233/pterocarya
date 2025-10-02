//P1115

#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n; cin >> n;
	int a, b, ans=INT_MIN;
	for(int i=0 ; i<n ; ++i){
		cin >> a;
		if(!i) b=a;
		else b = max(a, a+b);
		ans = max(ans, b);
	}
	
	cout << ans;
	
	return 0;
}

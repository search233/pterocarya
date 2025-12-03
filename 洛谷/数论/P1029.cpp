//P1029

#include <iostream>

using namespace std;

int main()
{
	int ans = 0;
	int x, y; cin >> x >> y;
	if(y%x==0){
		int fac = y/x;
		int curfac=2;
		ans = 1;
		while(fac>1){
			while(fac%curfac) ++curfac;
			while(fac%curfac==0) fac/=curfac;
			ans *= 2;
		}
	}
	cout << ans;
	
	return 0;
}

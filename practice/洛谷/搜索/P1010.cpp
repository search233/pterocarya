//P1010

#include <iostream>

using namespace std;

int pow2(int i){
	int res=1;
	for(int j=0 ; j<i ; ++j) res *= 2;
	return res;
}

void dfs(int n){
	for(int i=14 ; i>=0 ; --i){
		if(pow2(i)<=n){
			if(i==1) cout << '2';
			else if(i==0) cout << "2(0)";
			else{
				cout << "2(";
				dfs(i);
				cout << ')';
			}
			n -= pow2(i);
			if(n) cout << '+';
		}
	}
}

int main()
{
	int n; cin >> n;
	dfs(n);
	return 0;
}

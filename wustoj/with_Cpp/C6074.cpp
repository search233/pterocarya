//C6074

#include <iostream>
#include <cstdio>

using namespace std;

int list[100][100]={{0,}};

int main(){
	int n; cin >> n;
	
	int cnt=0;
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<=i ; ++j){
		 	list[i][j] = ++cnt;
		}
	}
	
	for(int i=n-1 ; i>=0 ; --i){
		int t = i;
		int m = n-i-1;
		for(int j=0 ; j<=m ; ++j){
			printf("%5d", list[t++][j]);
		}
		cout << '\n';
	}
	
	return 0;
}

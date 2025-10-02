//C6081

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int list[200][200];

int main(){
	int n; cin >> n;
	
	int cnt=0, tag=0;;
	for(int i=1-n ; i<=n-1 ; ++i){
		if(tag==0){
			tag=1;
			for(int j=0 ; j<n-abs(i) ; ++j){
				list[i+n-1][j] = ++cnt;
			}		
		}else{
			tag=0;
				for(int j=n-abs(i)-1 ; j>=0 ; --j){
					list[i+n-1][j] = ++cnt;
				}
		}
	}
	
	for(int i=n, t=n-1 ; i<2*n-1 ; ++i, --t){
		for(int j=n-1 ; j>=n-t ; --j){
			list[i][j] = list[i][j-(i-n+1)];
		}
	}
	
	for(int j=1,t=1; j<n ; ++j, ++t){
		for(int i=0 ; i<n ; ++i){
			list[i][j] = list[i+t][j];
		}
	}
	
	for(int i=0 ; i<n ; ++i){
		for(int j=
		0 ; j<n ; ++j){
			printf("%5d", list[i][j]);
		}
		cout << '\n';
	}
	
	return 0;
}

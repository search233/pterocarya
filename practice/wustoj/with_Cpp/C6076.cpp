//C6076

#include <iostream>

using namespace std;

int main(){
	int m, n; cin >> m >> n;
	
	int a[11][11] = {{0,}};
	int b[11][11] = {{0,}};
	a[5][5] = m;
	
	for(int l=0 ; l<n ; ++l){
		
		for(int i=1 ; i<=9 ; ++i){
			for(int j=1 ; j<=9 ; ++j){
				if(a[i][j]){
					b[i-1][j-1] += a[i][j];
					b[i-1][j] += a[i][j];
					b[i-1][j+1] += a[i][j];
					b[i][j-1] += a[i][j];
					b[i][j] += a[i][j] * 2;
					b[i][j+1] += a[i][j];
					b[i+1][j-1] += a[i][j];
					b[i+1][j] += a[i][j];
					b[i+1][j+1] += a[i][j];
				}
			}
		}
		
		for(int i=1 ; i<=9 ; ++i){
			for(int j=1 ; j<=9 ; ++j){
				a[i][j] = b[i][j];
				b[i][j] = 0;
			}
		}		
	}
	
	for(int i=1 ; i<=9 ; ++i){
		for(int j=1 ; j<=9 ; ++j){
			if(j==1) cout << a[i][j];
			else 	 cout << ' ' << a[i][j];
		}
		cout << '\n';
	}
	
	return 0;
	
}

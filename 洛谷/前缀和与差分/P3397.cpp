//P3397

#include <iostream>

using namespace std;

int a[1010][1010];

int main()
{
	int n, m; cin >> n >> m;
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j) a[i][j]=0;
	}
	
	for(int i=0 ; i<m ; ++i){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int j=x1 ; j<=x2 ; ++j) ++a[j][y1];
		for(int j=x1 ; j<=x2 ; ++j) --a[j][y2+1];
	}
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=2 ; j<=n ; ++j){
			a[i][j] += a[i][j-1];
		}
	}
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			cout << a[i][j] << ' ';
		}
		cout <<'\n';
	}
	
	return 0;
}

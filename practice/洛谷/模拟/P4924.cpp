//P4924

#include<iostream>

using namespace std;

int main()
{
	int n, m;	cin >> n >> m;
	int a[n+1][n+1], temp[n+1][n+1];
	int t=1;
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j) a[i][j] = t++;
	}
	
	int x, y, r, z;
	for(int k=0 ; k<m ; ++k){
		cin >> x >> y >> r >> z;
		
		for(int i=x-r ; i<=x+r ; ++i){
			for(int j=y-r ; j<=y+r ; ++j){
				temp[i][j] = a[i][j];
			}
		}
		
		int row, line; 
		if(z){
			
			row = x-r;
			line = y+r;
			for(int i=x-r ; i<=x+r ; ++i){
				for(int j=y-r ; j<=y+r ; ++j){
					a[i][j] = temp[row++][line];
				}
				--line;
				row = x-r;
			}
		}else{
			
			row = x+r;
			line = y-r;
			for(int i=x-r ; i<=x+r ; ++i){
				for(int j=y-r ; j<=y+r ; ++j){
					a[i][j] = temp[row--][line];
				}
				++line;
				row = x+r;
			}
		}
	}
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			if(j==1){
				cout << a[i][j];
			}else{
				cout << ' ' << a[i][j];
			}
		}
		cout << '\n';
	}
	
	return 0;
} 

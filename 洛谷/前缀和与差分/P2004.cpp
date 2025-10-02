//P2004

#include <iostream>
#include <climits>

using namespace std;

int a[1010][1010]={0};

int main()
{
	int n, m, c;
	cin >> n >> m >> c;
	
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			cin >> a[i][j];
			a[i][j] += a[i][j-1] + a[i-1][j];
			a[i][j] -= a[i-1][j-1];
		}
	}
	
	int x, y;
	int res = INT_MIN;
	for(int i=1 ; i<=n-c+1 ; ++i){
		for(int j=1 ; j<=m-c+1 ; ++j){
			int sum = a[i+c-1][j+c-1];
			sum += a[i-1][j-1];
			sum -= a[i+c-1][j-1] + a[i-1][j+c-1];
			if(sum>res){
				res=sum;
				x=i; y=j;
			}
		}
	}
	
	cout << x << ' ' << y;
	
	return 0;
}

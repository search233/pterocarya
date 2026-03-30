//P1979

#include <iostream>
#include <climits>

using namespace std;

int arr[200][200];


int main(){
	int n; cin >> n;

	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			cin >> arr[i][j];
			arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}
	
	int res=INT_MIN;
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			for(int y=1 ; y<=i ; ++y){
				for(int x=1 ; x<=j ; ++x){
					int sum = arr[i][j] - arr[y-1][j] - arr[i][x-1] + arr[y-1][x-1];
					res = max(res, sum);
				}
			}
		}
	} 
	
	cout << res;
	
	return 0;
}

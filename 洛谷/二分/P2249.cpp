//P2249

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000010];

int main(){
	int n, m; 
	scanf("%d%d", &n, &m);
	
	for(int i=0 ; i<n ; ++i) scanf("%d", &arr[i]);
	
	for(int i=0 ; i<m ; ++i){
		int num; scanf("%d", &num);
		
		int res = lower_bound(arr, arr+n, num) - arr;
		if(arr[res]!=num) res = -1;
		else res += 1;
		
		printf("%d ", res);
	}
	
	return 0;
}

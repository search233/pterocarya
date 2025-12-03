//p1036

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[30];



int dfs(int i, int cnt, int sum){
	
	if(cnt==k){
		if(sum<2) return 0;
		for(int j=2 ; j<=sum/j ; ++j){
			if(sum%j==0) return 0;
		}
		return 1;
	}
	
	int res=0;
	for(int j=i+1 ; j<n ; ++j){
		res += dfs(j, cnt+1, sum+arr[j]);
	}
	return  res;
}


int main()
{
	cin >> n >> k;
	
	for(int i=0 ; i<n ; ++i) cin >> arr[i];
	
	sort(arr, arr+n);
	int res=0;
	for(int i=0 ; i<n-k+1 ; ++i){
		res += dfs(i,1, arr[i]);
	}
	
	cout << res;
	
	return 0;
}

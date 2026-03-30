//P5194

#include<iostream>
typedef long long ll;

using namespace std;


ll n, c;
ll arr[1010];
ll psum[1010];
ll res = 0;

void dfs(int i, ll sum){
	if(sum>c) return;
	
	if(i>0 && sum + psum[i-1] <= c){
		res = max(res, sum+psum[i-1]);
		return;	
	}
	
	res = max(res, sum);
	
	for(int j=i-1 ; j>=0 ; --j){
		dfs(j, sum+arr[j]);
	}
	
	return;
}


int main()
{
	cin >> n >> c;
	for(int i=0 ; i<n ; ++i){
		cin >> arr[i];
		if(i==0) psum[i] = arr[i];
		else psum[i] = arr[i] + psum[i-1];
	}

	dfs(n, 0);
	cout << res;
	return 0;
}

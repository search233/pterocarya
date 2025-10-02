//P2678

#include <iostream>

using namespace std;

int a[50010];
int L, n, m;

bool judge(int mid){
	int sum=0, pos=0;
	for(int i=1 ; i<=n+1 ; ++i){
		if(a[i]-a[pos] < mid) ++sum;
		else pos = i;
	}
	
	if(sum>m) return 0;
	else return 1; 
}

int main(){
	cin >> L >> n >> m;
	a[0]=0; a[n+1]=L;
	for(int i=1 ; i<=n ; ++i) cin >> a[i];
	
	int l=0, r=L, res;
	
	while(l<=r){
		int mid = (l+r)/2;
		if(judge(mid)){
			res = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	
	cout << res;
	
	return 0;
}

//P3853

#include <iostream>

using namespace std;

int L, N, K;
int a[100010];

bool judge(int x){
	int pos=0, sum=0;
	for(int i=0 ; i<N ; ++i){
		while(a[i]-pos>x){
			pos += x;
			++sum;
			if(sum>K) return 0;
		}
		
		pos = a[i];
	}
	
	return sum<=K; 
}

int main(){
	cin >> L >> N >> K;
	for(int i=0 ; i<N ; ++i) cin >> a[i];

	int l=0, r=L, res;

	while(l<=r){
		int mid = (l+r)/2;
		if(judge(mid)){
			res = mid;
			r = mid-1;
		}else l = mid+1;
	}
	
	cout << res;
	
	return 0;
}

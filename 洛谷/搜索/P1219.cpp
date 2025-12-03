//P1219

#include <iostream>

using namespace std;

int m1[30], m2[30], m3[30];
//  列， 顺对角线， 逆对角线
int cnt=0, n, ans[20]; 

void dfs(int row){
	if(row>n){
		++cnt;
		if(cnt<=3){
			for(int i=1 ; i<=n ; ++i){
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}	
		return;
	}
	for(int i=1 ; i<=n ; ++i){
		if(m1[i] || m2[i-row+n] || m3[i+row]) continue;
		m1[i] = m2[i-row+n] = m3[i+row] = 1;
		ans[row] = i;
		dfs(row+1);
		m1[i] = m2[i-row+n] = m3[i+row] = 0;
	}
}

int main(){
	cin >> n;
	dfs(1);
	cout << cnt;
	return 0;
}

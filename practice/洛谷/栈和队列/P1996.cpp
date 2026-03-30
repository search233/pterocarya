//P1996 

#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	queue<int> qu;
	
	for(int i=1 ; i<=n ; ++i){
		qu.push(i);
	}
	
	int cnt=1;
	while(!qu.empty()){
		int t;
		t=qu.front();
		qu.pop();
		if(cnt==m){
			cnt=1;
			cout << t <<' ';
			cout << t <<' ';
		}else{
			qu.push(t);
			++cnt;
		}
	}
	
	return 0;
}

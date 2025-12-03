//P1540

#include <iostream>
#include <queue>
#include <map>

using namespace std;

queue<int> qu;
map<int,int> mp;

int main(){
	int m, n; cin >> m >> n;
	
	int cnt=0;
	
	for(int i=0 ; i<n ; ++i){
		int t; cin >> t;
		if(!mp[t]){
		
			if((int)qu.size()==m){
				mp[qu.front()]=0;
				qu.pop();
			}			
			++cnt;
			mp[t]=1;
			qu.push(t);
		}
	} 
	
	cout << cnt;
	
	return 0;
}

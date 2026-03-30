//C6077

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<int> arr;
	int cnt=0;
	
	while(1){
		int t; cin >> t;
		if(t==0) break;
		else arr.push_back(t);
		++cnt;
	}
	
	while(1){
		int t; cin >> t;
		if(t==0) break;
		else arr.push_back(t);
		++ cnt;
	}
	
	sort(arr.begin(), arr.end());
	
	cout << arr[0];
	for(int i=1 ; i<cnt ; ++i){
		if(arr[i]==arr[i-1]) continue;
		cout << ' ' << arr[i];
	}
	
	return 0;
}

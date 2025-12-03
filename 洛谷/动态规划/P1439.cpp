//P1439

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int list[100001], arr[100001];

int lis(int n){ 
	vector<int> a;
	
	for(int i=1 ; i<=n ; ++i){
		auto it = lower_bound(a.begin(), a.end(), arr[i]);
		if(it==a.end()) a.push_back(arr[i]);
		else *it = arr[i];
	}
	return (int)a.size();
}

int main()
{
	int n; cin >> n;
	
	for(int i=1 ; i<=n ; ++i){
		int t; cin >> t;
		list[t] = i;
	}
	
	for(int i=1 ; i<=n ; ++i){
		int t; cin >> t;
		arr[i] = list[t];
	}
	
	cout << lis(n);
	
	return 0;
} 

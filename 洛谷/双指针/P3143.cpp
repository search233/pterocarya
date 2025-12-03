//P3143

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){ return a<b;}

int main(){
	int n, k; cin >> n >> k;
	
	vector<int> a(n);
	
	for(int i=0 ; i<n ; ++i) cin >> a[i];
	
	sort(a.begin(), a.end(), comp);
	
	int num1=0, num2=0;
	
	for(int i=0, j ; i<n ; ++i){
		 
	}
	
	cout << num1+num2;
	
	return 0;
} 

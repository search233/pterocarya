//P1020

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int lis(){	//最长上升子序列 
	vector<int> a;
	
	for(int i : arr){
		auto it=lower_bound(a.begin(), a.end(), i);
		if(it==a.end()) a.push_back(i);
		else *it = i;
	}
	
	return (int)a.size();
}


int lnds(){ //最长不上升子序列 
	vector<int> a;
	
	for(int i : arr){
		auto it=upper_bound(a.begin(), a.end(), i, greater<int>());
		if(it==a.end()) a.push_back(i);
		else *it = i;
	}
	
	return (int)a.size();
}


int main()
{
	int num;
	while(cin >> num){
		arr.push_back(num);
	}
	
	cout << lnds() << '\n' << lis() ;
	return 0;
}

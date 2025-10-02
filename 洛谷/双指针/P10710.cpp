//P10710

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct id{
	int c;
	int h;
}; 

bool comp(id a, id b){
	return a.h < b.h;
}


int main(){
	int n, s;
	cin >> n >> s;
	
	vector<id> a;
	
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<s ; ++j){
			int t; cin >> t;
			a.push_back({i,t});
		}
	}
	
	sort(a.begin(), a.end(), comp);
	
	int res=-1;
	int list[1000]={0}, sum=0;
	for(int i=0 , j=0; j<n*s ; ++j){
		if(list[a[j].c]==0) ++sum;
		
		++list[a[j].c];
		
		if(n==sum){
			while(list[a[i].c]>1){
				--list[a[i++].c];
			}
			if(res==-1) res = a[j].h-a[i].h;
			else res = min(res, a[j].h-a[i].h);
		}
	}
	
	cout << res;
	
	return 0;
}

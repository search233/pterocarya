//C6078

#include <iostream>
#include <map> 
#include <vector>

using namespace std;

struct node{
	int b;
	int c;	
};

int main(){
	int n; cin >> n;
	map<int, node> mp;
	
	int sum=0;
	
	for(int i=1 ; i<=n ; ++i){
		int ta, tb, tc;
		cin >> ta >> tb >> tc;
		if(mp[ta].b==1) continue;
		else{
			
			if(tb==1){
				mp[ta].b=1;
				sum += mp[ta].c+tc;
			}else{
				mp[ta].c += 20;
			}
		}
	}
	
	cout << sum;
	
	return 0;
}

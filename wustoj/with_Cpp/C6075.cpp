//C6075

#include<iostream>
#include<vector>

using namespace std;

int main(){
	int l, m; cin >> l >> m;
	vector<int> list(l+2);
	
	fill(list.begin(), list.end(), 1);
	
	for(int i=0 ; i<m ; ++i){
		int tag1, tag2; cin >> tag1 >> tag2;
		for (int j=tag1 ; j<=tag2 ; ++j) list[j]=0;
	}
	
	int sum=0;
	for(int i=0 ; i<=l ; ++i)	if(list[i]) ++sum;
	
	cout << sum;
	
	return 0;
}

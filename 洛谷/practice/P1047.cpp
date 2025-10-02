//P1047

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
	
	vector<int> tree;
	int l, m;	scanf("%d %d", &l, &m);
	int u, v, cnt=0;
	
	tree.reserve(l+1);
	for(int i=0 ; i<=l ; i++){
		tree[i] = 1;
	}
	
	while(m>0){
		scanf("%d %d", &u, &v);
		for(int i=u ; i<=v ; i++){
			tree[i] = 0;
		}
		m--;
	}
	
	for(int i=0 ; i<=l ; i++){
		if(tree[i]==1){
			cnt++;
		}
	}	
	
	cout << cnt << endl;
	
	return 0; 
}

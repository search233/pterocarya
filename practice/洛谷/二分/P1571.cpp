//P1571

#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];
int b[100010];

int main(){
	int n, m; cin >> n >> m;
	
	for(int i=0 ; i<n ; ++i) scanf("%d", &a[i]);
	for(int i=0 ; i<m ; ++i) scanf("%d", &b[i]);
	
	sort(b, b+m);
	
	for(int i=0 ; i<n ; ++i){
		int pos=lower_bound(b,b+m,a[i])-b;
		if(b[pos]==a[i]) printf("%d ", a[i]);
	}
	
	return 0;
}

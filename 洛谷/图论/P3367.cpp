//P3367

#include <iostream>

using namespace std;

int arr[200010];

int find(int x){
	if(x==arr[x]){
		return arr[x];
	}else  return arr[x] = find(arr[x]);
}

void join(int x, int y){
	int tx = find(x);
	int ty = find(y);
	if(tx != ty){
		arr[ty] = tx;
	}
}

int main(){
	int n, m; cin >> n >> m;
	
	for(int i=1 ; i<=n ; ++i) arr[i]=i;
	
	for(int i=0 ; i<m ; ++i){
		int z, x, y;
		cin >> z >> x >> y;
		
		if(z==1){
			join(x,y);
		}else{
			if(find(x)==find(y)) cout << 'Y' << '\n';
			else cout << 'N' << '\n';
		}
	}
	
	return 0;
}

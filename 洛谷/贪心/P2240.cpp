//P2240

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct gold{
	int m;
	int v;
	double rate;
}g[100];

bool cmp(gold a, gold b);

int main(){
	int n, t;	cin >> n >> t;
	
	for(int i=0 ; i<n ; ++i){
		cin >> g[i].m >> g[i].v;
		g[i].rate = (double)g[i].v / g[i].m; 	
	}
	
	sort(g, g+n, cmp);
	
	double sum=0, wight=0;

		
	for(int i=0 ; i<n ; i++){
		
		if(g[i].m<=(t-wight)){
			wight += g[i].m;
			sum += g[i].v;
		}else{
			sum += g[i].rate * (t-wight);
			break;
		}
	}

	printf("%.2f", sum);
	
	return 0;
}

bool cmp(gold a, gold b){
	return a.rate > b.rate;
}

//P2251

#include <iostream>
using namespace std;

int n, m;
int f[100005][21], Log[100005];

void pre(){
	for(int i=2; i<=n ; ++i)
		Log[i] = Log[i>>1]+1;
		
	for(int j=1 ; j<=Log[n] ; ++j)
		for(int i=1 ; i<=n-(1<<j)+1 ; ++i)
			f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
}


int main()
{
	cin >> n >> m;
	
	for(int i=1 ; i<=n ; ++i) cin >> f[i][0];
	
	pre();

	for(int i=1 ; i<=n-m+1 ; ++i){
		int s = Log[m];
		cout << min(f[i][s], f[i+m-(1<<s)][s]) << '\n'; 
	}
	
	return 0;
}

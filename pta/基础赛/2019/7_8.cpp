//7_8

#include<stdio.h>
#define ll long long

ll f(ll x, ll y, ll a, ll b, ll c, ll d, ll e);

int main()
{
	int T;	scanf("%d", &T);
	for(int i=0 ; i<T ; ++i){
		int n, m;	scanf("%d %d", &n, &m);
		ll a, b, c, d, e;
		scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);
		
		ll temp;
		ll min;
		for(int x=1-n ; x<n ; ++x){
			for(int y=1-m ; y<m ; ++y){
				temp = f(x,y,a,b,c,d,e);
				if(x==1-n && y==1-m){
					min = temp;
				}else if(min>temp){
					min = temp;
				}
			}
		}
		
		printf("%lld\n", min);
	}
	
	return 0;
}

ll f(ll x, ll y, ll a, ll b, ll c, ll d, ll e){
	return a*x*x + b*x + c*y*y + d*y + e;
}

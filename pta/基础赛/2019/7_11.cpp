//7_11

#include<stdio.h>
#define ll long long

int main()
{
	ll ret[10001] = {0,};
	ll n;
	int T;	
	scanf("%d", &T);
	
	
	for(int i=0 ; i<T ; i++){
		scanf("%lld", &n);
		
		for(int j=0 ; j<n ; j++){
			ret[i] += (n-j) * (j+1);
			
		}
		ret[i] += n * (n-1) / 2;
		
		ret[i] +=  (n-1)*(n-2) ;
		
		if(n>3) ret[i] += (n-2)*(n-3)/2;
	}
	
	for(int i=0 ; i<T ; i++){
		printf("%lld\n", ret[i]);
	}
	
	return 0;
} 

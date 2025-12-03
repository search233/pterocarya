//C5040

#include<stdio.h>
#include<math.h>

int prime( int x )
{
	for(int i=2 ; i<=(int)sqrt(x) ; i++ ){
		
		if( x%i==0 && x>1){
			return 0;
		}
	}
	
	return 1;
}

int main()
{
	int N, p, q;
	
	scanf("%d", &N);
	
	for(int i=2 ; i<=N/2 ; i++ ){
		
		if( prime(i) ){
			p = i;
			
			if( prime( N-p ) ){
				q = N - p;
				break;
			}
		}
	}
	
	printf("%d = %d + %d", N, p, q);
	
	return 0;
	
}

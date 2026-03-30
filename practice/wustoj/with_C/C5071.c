#include<stdio.h>

int f(int a,int b)
{
	return ( b*(b+1)*(b*2+1) - a*(a-1)*(2*a-1) ) / 6;
} 

int main()
{
	int n, A, B;
	
	scanf("%d", &n);
		
		int i = n *(1+2*n); 
		A = f( i, i+n);
		B = f( i+n+1, i+n*2);		
		
		
		if( A==B ){
			
			for(int j=i ; j<=i+n ; j++){
				
				printf("%d^2 ", j);
				
				if( j!=i+n ){
					printf("+ ");
				}
			}
			
			printf("= ");
			
			for(int j=i+n+1 ; j<=i+n*2 ; j++ ){
				
				printf("%d^2 ", j);
				
				if( j!=i+n*2 ){
					printf("+ ");
				}
			}
		}
	
	return 0;
}

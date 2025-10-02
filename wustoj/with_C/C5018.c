//C5018

#include<stdio.h>

int main()
{
	int N, n, sum, left, num;
	
	scanf("%d", &N);
	
	
	
	for( int i=1 ; i<=N ; i++ ){	
		
		sum = i * i * 2 - 1;
		
		left = N - sum;
		
		if( left<0 ){
			n = i - 1;			 
			sum = n*n*2 - 1;
			break;	
		}else if( left==0 ){	 
			n = i;
			break;
		}
	}
	
	num = 2*n - 1; 			
	

	for ( int i=1 ; i<=n*2-1 ; i++ ){		
		
		if( i<=n ){			
			
			for( int j=1 ; j<=i-1 ; j++ ){		
				printf(" ");
				
			}
			
			for( int j=1 ; j<=num+2*(1-i) ; j++ ){	
				printf("*");
				
			}
				
		}else{

			for( int j=1 ; j<=2*n-i-1 ; j++ ){	
				printf(" ");
				
			}
			
			for( int j=1 ; j<=2*(i-n+1)-1 ; j++ ){	
				printf("*");
				
			}
			
		}
		

		printf("\n");
	}
	
	left = N - sum; 
	
	printf("%d", left);
	
	
	return 0;
} 

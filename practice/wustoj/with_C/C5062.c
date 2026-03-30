//C5062

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; i++ ){
		
		int max = (n-1)/2, long_line=(n+1)/2;
		
		for(int j=abs(max-i+1) ; j>0 ; j-- ){
			printf(" ");
		}
		
		if( i==1 || i==n ){
			printf("*\n");
			
		}else{
			printf("*");
			
			if( i>1 && i<=long_line ){
			
				for(int j=1 ; j<=2*i-3 ; j++ ){
					printf(" ");
				}
			}else{
				for(int j=1 ; j<=(n-2)-2*(i-long_line) ; j++ ){
					printf(" ");
				}
			}
			
			printf("*\n");
		}
	}
	
	return 0;
}

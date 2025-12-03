//C5046

#include<stdio.h>

int main()
{
	int N;
	
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; i++ ){
		
		for(int j=1 ; j<=i ; j++){
			
			printf("%d*%d=%d", i, j, i*j );
			
			if( i*j<10 ){
				printf("   ");
			}else{
				printf("  ");
			}
		}
		
		printf("\n");
	}
	
	return 0;
} 

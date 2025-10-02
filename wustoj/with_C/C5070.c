//C5070

#include<stdio.h>


int main( )
{
	int m, C[32][32] = {1,};
	
		
	for(int i=0, j=0 ; i<32 ; i++ ){
	 	C[i][j] = 1;
	}
	
	for(int i=1 ; i<32 ; i++ ){
		
		for(int j=1 ; j<=i ; j++ ){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
	
	
	scanf("%d", &m);
	
	for(int i=0 ; i<m ;  i++){
		
		for(int j=1 ; j<=5*(m-i-1) ; j++ ){
			printf(" ");
		}
		
		for(int j=0 ; j<=i ; j++ ){
			printf("%10d", C[i][j] );
		}
		
		printf("\n");
	}
	
	return 0;
}

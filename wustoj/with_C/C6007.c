//C6007

#include<stdio.h>

int main()
{
	int m, n, temp, line;
		
	scanf("%d %d", &m, &n);
		
	int A[30][30];
		
	for(int i=0 ; i<m ; i++){
			
		for(int j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	} 
	
	temp = A[0][0];
	
	printf("before:\n");
	
	for(int i=0 ; i<m ; i++){
			
		for(int j=0 ; j<n ; j++){
			
			if( A[i][j] < temp ){
				temp = A[i][j];
				line = i;
			} 
			
			printf("%4d", A[i][j]);
		}
		
		printf("\n");
	} 	
	
	for(int j=0 ; j<n ; j++){
		temp = A[m-1][j];
		A[m-1][j] = A[line][j];
		A[line][j] = temp;
	}
	
	printf("after:\n");
	
	for(int i=0 ; i<m ; i++){
			
		for(int j=0 ; j<n ; j++){
			
			if( A[i][j] < temp ){
				temp = A[i][j];
				line = i;
			} 
			
			printf("%4d", A[i][j]);
		}
		
		printf("\n");
	} 	
	
	return 0;
}

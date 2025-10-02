//C6006

#include<stdio.h>

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	int A[10][10];
	
	for(int i=0; i<n; i++){
		
		for(int j=0; j<m; j++){
			scanf("%d", &A[i][j]);
		}
	} 
	
	
	for(int i=0; i<n; i++){
		
		for(int j=0; j<m; j++){
			
			if(j==0){
				printf("%d", A[i][j]);
			}else{ 
				printf(" %d", A[i][j]);
			}
			
			if(j==m-1){
				printf("\n");
			}
		}
	}
	
	for(int i=0; i<m; i++){
			
		for(int j=0; j<n; j++){
				
			if(j==0){
				printf("%d", A[j][i]);
			}else{ 
				printf(" %d", A[j][i]);
			}
			
			if(j==n-1){
				printf("\n");
			}
		}
	}
	
	return 0;
}

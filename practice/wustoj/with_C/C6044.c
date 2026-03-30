//C6044

#include<stdio.h>

int main()
{
	int n;
	int A[100][100] = {0};
	
	scanf("%d", &n);
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(i==j || i+j==n-1){
				A[i][j] = 0;
			}
			
			if(i<j){
				
				if(i+j<n-1){
					A[i][j] = 1;
				}else if(i+j>n-1){
					A[i][j] = 4;
				}
			}else if(i>j){
				
				if(i+j<n-1){
					A[i][j] = 2;
				}else if(i+j>n-1){
					A[i][j] = 3;
				}
			}
		}
	}
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(j==0){
				printf("%d", A[i][j]);
			}else{
				printf(" %d", A[i][j]);
			}
		}
		
		printf("\n");
	}
	
	return 0;
}

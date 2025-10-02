//C6043

#include<stdio.h>

int main()
{
	int n, i, j;
	int A[10][10] = {0,};
	
	scanf("%d", &n);
	
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			scanf("%d", &A[i][j]);
			
			if(j==0){
				A[i][n] = A[i][j];
			}else if(A[i][j]>A[i][n]){
				A[i][n] = A[i][j];
			}
			if(i==0){
				A[n][j] = A[i][j];
			}else if(A[i][j]<A[n][j]){
				A[n][j] = A[i][j];
			}
		}
	}
	
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			if(A[i][n]==A[n][j]){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	
	printf("NONE");
	
	return 0;
}

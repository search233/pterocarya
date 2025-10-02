//C6045

#include<stdio.h>

int main()
{
	int N, X, i;
	int A[21] = {0,};
	
	scanf("%d %d", &N, &X);
	
	for(i=0 ; i<N ; i++){
		scanf("%d", &A[i]);
	}
	
	for(i=0 ; i<N ; i++){
		if(A[i]==X){
			printf("%d", i);
			return 0;
		}
		if(i==N-1){
			printf("Not Found");
			return 0;
		}
	}		
} 

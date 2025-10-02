//C6040

#include<stdio.h>

int main()
{
	int N, M, A[1000] = {0,};
	
	scanf("%d %d", &N, &M);
	
	for(int i=0 ; i<N ; i++){
		scanf("%d", &A[i]);
	}
	
	M %= N;
	
	for(int i=N-1 ; i>=0 ; i--){
		A[i+M] = A[i];
	}
	for(int i=N ; i<=N-1+M ; i++){
		A[i-N] = A[i];
	}
	
	for(int i=0 ; i<N ; i++){
		if(i==0){
			printf("%d", A[i]);
		}else{
			printf(" %d", A[i]);
		}
	}
	
	return 0;
}

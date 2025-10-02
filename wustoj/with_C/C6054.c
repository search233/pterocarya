//C6054

#include<stdio.h>

int main()
{
	int A, N;	scanf("%d %d", &A, &N);
	int S[N+1];

	if(!N){
		printf("%d", 0);
		return 0;
	}

	
	S[0] = A*N;
	for(int i=1, t=N-1 ; i<=N ; ++i, --t){
		S[i] = S[i-1]/10 + t*A;
		S[i-1] %= 10;
	}
	
	for(int i=N ; S[N]==0 ; i--){
		N--;
	}
	
	while(N>=0){
		printf("%d", S[N]);
		N--;
		
	}
	
	return 0;
}

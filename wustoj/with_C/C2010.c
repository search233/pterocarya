//C2010

#include<stdio.h>

int main()
{
	int N, K, M;
	
	scanf("%d %d %d", &N, &K, &M);
	
	printf("%d", N - (M * K));
	
	return 0;
}

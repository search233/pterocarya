//C5045

#include<stdio.h>

int main()
{
	int N, U, D, time=0, S=0;
	
	scanf("%d %d %d", &N, &U, &D);
	
	while( N-S>U ){
		S += U;
		time += 1;
		
		S -= D;
		time += 1;	
	}
	
	time += 1;
	
	printf("%d", time);
	
	return 0;
}

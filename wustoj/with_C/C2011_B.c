//C2011_B

#include<stdio.h>

int main()
{
	int T1, T2_H, T2_M, P, temp;
	
	scanf("%d %d", &T1, &P);
	
	temp = (T1 / 100 * 60) + (T1 % 100) + P;
	
	T2_H = temp / 60 ;
	
	T2_M = temp % 60;
	
	printf("%d%02d", T2_H,T2_M);
	
	return 0;
}

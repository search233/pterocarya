//C2002

#include<stdio.h>

int main()
{
	int A,B;
	
	int a,b,c,d;
	
	scanf("%d %d", &A, &B);
	
	a = A + B ;
	
	b = A - B ;
	
	c = A * B ;
	
	d = A / B ;
	
	printf("%d + %d = %d\n", A, B, a);
		
	printf("%d - %d = %d\n", A, B, b);
		
	printf("%d * %d = %d\n", A, B, c);
		
	printf("%d / %d = %d\n", A, B, d);
	
	return 0;
}

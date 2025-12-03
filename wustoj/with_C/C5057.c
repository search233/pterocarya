//C5057

#include<stdio.h>

int main()
{
	int A, B, num;

	scanf("%d %d", &A, &B);
	
	num = A * B;
	
	while( num ){
		printf("%d", num % 10 );
		num /= 10;
	}
	
	return 0;
}


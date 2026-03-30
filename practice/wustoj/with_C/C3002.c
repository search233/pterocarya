//C3002

#include<stdio.h>

int main()
{
	int a, b, c;
	
	int num;
	
	scanf("%d", &num);
	
	a = num / 100;
	
	c = num % 10;
	
	b = (num % 100 - c) / 10;
	
	num = (c * 100) + (b * 10) + a;
	
	printf("%03d",num);
	
	return 0;
}

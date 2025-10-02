//C2001

#include<stdio.h>

int main()
{
	int num;
	
	scanf("%d",&num);
	
	int a,b,c,d;
	
	d = num / 1000;
	
	c = (num - d*1000)/100;
	
	a = num % 10;
	
	b = (num % 100 ) / 10; 
	
	printf("%d=%d+%d*10+%d*100+%d*1000", num, a, b, c, d);
	
	return 0;
}

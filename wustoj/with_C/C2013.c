//C2013

#include<stdio.h>

int main()
{
	int x, y, z;
	
	int x1, y1, z1;
	
	scanf("%d %d %d", &x, &y, &z);
	
	x1 = x / 3;
	
	y1 = (x1 + y) / 3;
	
	z1 = (x1 + y1 + z) / 3;
	
	x1 += z1;
	
	x1 += y1;
	
	y1 += z1; 
	
	printf("%d %d %d", x1, y1, z1);
	
	return 0;
}

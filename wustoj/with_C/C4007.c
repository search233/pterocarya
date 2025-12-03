//C4007

#include<stdio.h>

int main()
{
	int num, x, y, z;
	
	scanf("%d %d %d", &x, &y, &z);
	
	num = (x > y) ? ((x > z) ? ((y > z) ? y : z) : x) : ((y > z) ? ((x > z) ? x : z) : y); 

	printf("%d", num);
	
	return 0;
}

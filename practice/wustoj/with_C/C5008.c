//C5008

#include<stdio.h>

int main()
{
	int x, y1, y2, y3, sum, minus, i=0;
	
	scanf("%d %d %d %d", &x, &y1, &y2, &y3);
	
	sum = y1 + y2 + y3;
	
	minus = x - sum; 
	
	while( minus > 0 ){
		i++;
		
		minus -= 2;
		
		//printf("%d\n", minus);
	}
	
	printf("%d", i);
	
	return 0;
}

//C3011

#include<stdio.h>
#include<math.h>

int main()
{
	int Y;
	
	double rate;
	
	scanf("%d", &Y);
	
	rate = pow(2 , 1.0 / Y) - 1;
	
	printf("%.2f%%", rate * 100);
	
	return 0;
} 


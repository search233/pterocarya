//C3006

#include<stdio.h>

int main()
{
	double a, b, c, d, sum;
	
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	
	sum = a * 2.5 + b * 1.7 + c * 2.0 + d * 1.2;
	
	printf("%.2f", sum);
	
	return 0;
} 

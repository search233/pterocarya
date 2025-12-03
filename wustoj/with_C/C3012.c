//C3012

#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, r;
	
	scanf("%lf %lf", &a, &b);
	
	r = fmod( a , b );
	
	printf("%g", r);
	
	return 0;
}

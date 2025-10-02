//C3001

#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, S, P, temp;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	P = (a + b + c) / 2;
	
	temp = P * (P-a) * (P-b) * (P-c);

	S = sqrt(temp);
	
	printf("%.2f", S);
	
	return 0;
}

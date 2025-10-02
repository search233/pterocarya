//C3008

#include<stdio.h>

int main()
{
	double capital, interest, interest_rate, sum;
	
	scanf("%lf %lf", &capital, &interest_rate);
	
	interest = capital * interest_rate / 100;
	
	sum = interest + capital;
	
	printf("%11.2f\n%11.2f\n%11.2f", capital, interest, sum);
	
	return 0;
}


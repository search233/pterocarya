//C2003

#include<stdio.h>

int main()
{
	int num_1, num_2, num_3, num_4 ;
	int Sum ;
	double Average ;
	
	scanf("%d %d %d %d",  &num_1, &num_2, &num_3, &num_4);
	
	Sum = num_1 + num_2 + num_3 + num_4;
	Average = Sum / 4.0 ;
	
	printf("Sum = %d\nAverage = %.2f", Sum, Average) ;
	
	return 0;
}


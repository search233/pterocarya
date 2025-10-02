//C5053

#include<stdio.h>

int main()
{
	int N;
	double S=0, temp, average;
	
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; i++ ){
		scanf("%lf", &temp);
		S += 1.0 / temp;
	}
	
	S /= N;
	
	average = 1.0 / S;
	
	printf("%.2f", average);
	
	return 0;
}

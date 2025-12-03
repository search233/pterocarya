//C5010

#include<stdio.h>

int main()
{
	double n, temp=0, PI, i;
	
	
	scanf("%lf", &n);
	
	
	for( i=1 ; i<=n ; i++ ){
		
		temp += 1 / (4 * i - 3) - 1 / (4 * i - 1);
		
		PI = temp * 4;
	}
	
	
	printf("%f", PI);
	
	
	return 0;
}

//C4020

#include<stdio.h>
#include<math.h>

int main()
{
	double x, y, z = 0;
	
	scanf("%lf", &x);
	
	if(x <= 2.5){
		
		y = pow(x,2) + 1;
		
	}else{
		
		y = pow(x,2) - 1;
		
	}
	
	
	if(x >= 1 && x < 2){
		
		z = 3 * x + 5;
		
	}else if(x >= 2 && x < 3){
		
		z = sin(x) * 2 - 1;
		
	}else if(x >= 3 && x < 5){
		
		z = sqrt(1 + pow(x,2)); 
		
	}else if(x >= 5 && x < 8){
		
		z = pow(x,2) - 2 * x + 5;
		
	}
	
	printf("%f\n%f", y, z);
	
	return 0;
}

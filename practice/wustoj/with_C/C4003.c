//C 4003

#include<stdio.h>

int main()
{
	int Y;
	
	scanf("%d", &Y);
	
	if(Y % 400 == 0 || (Y % 100 != 0 && Y % 4 == 0)){
		printf("%d is a leap year!", Y);
	}else{
		printf("%d isn't a leap year!", Y);
	}
	
	return 0;	
} 

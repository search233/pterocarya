#include<stdio.h>

int main()
{
	int a, b;
	int c = 0 ; 
	
	scanf("%d %d", &a, &b);
	
	if(a % b != 0){
		c = a / b + 1;
	} else{
		c = a / b;
	}
	
	printf("%d", c);
	
	return 0;
}

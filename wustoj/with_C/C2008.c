//C2008

#include<stdio.h>

int main()
{
	int price;
	
	float payment, discount ;
	
	scanf("%d %f", &price, &discount);
	
	payment = price * discount * 0.1;
	
	printf("%.2f", payment);
	
	return 0;
}

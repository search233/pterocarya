//C2006_A(if-else)

#include<stdio.h>

int main()
{
	int D;
	
	scanf("%d", &D);
	
	if(D <= 5){
		D += 2;
	}else{
		D += 2 - 7;
	}
	
	printf("%d", D);
	
	return 0;
}

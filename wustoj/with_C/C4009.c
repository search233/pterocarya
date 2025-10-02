//C4009

#include<stdio.h>

int main()
{
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if(a < 12) {
		printf("%d %d %d AM", a, b, c);
	}else{
		printf("%d %d %d PM", a - 12, b, c);
	}
	
	return 0;
	
}

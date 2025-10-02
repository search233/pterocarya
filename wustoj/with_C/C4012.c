//C4012

#include<stdio.h>

int main()
{
	int N, temp;
	
	scanf("%d", &N);
	
	temp = N % 5;
	
	switch(temp){
		case 0:
		case 4:
			printf("Drying in day %d", N);
			break;
		case 1:
		case 2:
		case 3:
			printf("Fishing in day %d", N);
			break;
	}
	
	return 0;
}

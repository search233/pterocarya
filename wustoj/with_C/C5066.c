//C5066

#include<stdio.h>

int main()
{
	int A, flag = 0;
	
	scanf("%d", &A);
	
	if( A<=2000 ){
		printf("Invalid year!");
		return 0;
	}
	
	for(int i=2001 ; i<=A ; i++ ){
		
		if( (i%4==0 && i%100!=0) || i%400==0 ){
			printf("%d\n", i); 
			flag = 1;
		}
	}
	
	if( flag==0 ){
		printf("None");
	}
	
	return 0;
}

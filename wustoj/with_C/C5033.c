//C5033

#include<stdio.h>

int main()
{
	int temp, sum=0;
	
	for(int i=1 ; ; i++ ){
		
		scanf("%d", &temp);
		
		if( temp<=0 ){
			break;
		}		
		
		if( temp%2!=0 ){
			sum += temp;
		}
		
	}
	
	printf("%d", sum);
	
	return 0;
}

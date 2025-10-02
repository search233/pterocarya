//C5021 

#include<stdio.h>

int main()
{
	int temp, cnt=0;
	
	do{
		scanf("%d", &temp);
		
		cnt++;
		
	}while(temp!=250);
	
	printf("%d", cnt);
	
	return 0;
}

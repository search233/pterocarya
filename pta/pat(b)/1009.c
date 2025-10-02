//1009

#include<stdio.h>

int main()
{
	char arr[90][90];
	int i;

	for(i=0 ; scanf("%s", arr[i])!=EOF ; i++);
	i--;
	
	for( ; i>=0 ; i--){
		printf("%s", arr[i]);
		if(i>0)	printf(" ");
	}
	
	return 0;
}

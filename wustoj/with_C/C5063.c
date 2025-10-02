//C5063

#include<stdio.h>

int prime(int x)
{
	int flag = 1;
	
	for(int i=2 ; i<x ; i++ ){
		
		if( x%i==0 ){
			flag = 0;
			break;
		}
	}
	
	return flag;
}

int main()
{
	int a;
	
	scanf("%d", &a);
	
	for(int i=a ; ; i++ ){
		
		if( prime(i)==1 && prime(i+2)==1 ){
			printf("%d %d", i, i+2);
			break;
		}
	}
	
	return 0;
}

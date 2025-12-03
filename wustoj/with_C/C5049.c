//C5049

#include<stdio.h>

int gcd( int x,int y ){
	
	int temp;
	
	if( y<x ){
		temp = y;
		y = x;
		x = temp;
	}
	
	while( y!=0 ){
		temp = y;
		y = x % y;
		x = temp;
	}
	
	return x;
}


int main()
{
	int a, b, temp;
	
	scanf("%d/%d", &a, &b);
	
	temp = a;
	
	temp /= gcd(a,b);
	
	b /= gcd(a,b);
	
	a = temp;
	
	printf("%d/%d", a, b);
	
	return 0;
}

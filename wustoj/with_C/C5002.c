//C5002

#include<stdio.h>

int gcd( int a, int b ){
	int temp;
	
	while( b!=0 ){
		temp = b;
		
		b = a % b;
		
		a = temp;
	}
	
	return a;
}



int main()
{
	int x, y, tem;
	
	scanf("%d %d", &x, &y);
	
	if( x<y ){
		tem = y;
		
		y = x;
		
		x = tem;
	}
	
	printf("%d", gcd( x,y ));
	
	return 0;
}

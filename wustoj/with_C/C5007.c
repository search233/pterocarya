//C5007

#include<stdio.h>

int main()
{
	int n, a=1, b=0, c, i;
	
	scanf("%d", &n);
	
	for( i=1 ; i<=n ; i++){
		
	printf("%10d", a);
	
	c = a;
	a = a + b;
	b = c;
	
	if( i%5 == 0 ){
		printf("\n");
	}
	}
	
	return 0;
}

//C5005

#include<stdio.h>

int main()
{
	int n, i;
	
	double Sn = 0, An, a=2, b=1, tmp;
	
	scanf("%d", &n);
	
	for( i=1 ; i<=n ; i++ ){
		
		An = a / b;
		
		tmp = a;
		a = a + b;
		b = tmp;
				
	 	Sn += An;
	}
	
	 
	printf("%f", Sn);
	
	return 0;
}

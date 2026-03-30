//C5031

#include<stdio.h>

int main()
{
	int a, n, S=0, An=0;
	
	scanf("%d %d", &a, &n);
	
	for(int i=1 ; i<=n ; i++ ){
		An = An*10 + a; 
		S += An;
	}
	
	printf("%d", S);
	
	return 0;
}

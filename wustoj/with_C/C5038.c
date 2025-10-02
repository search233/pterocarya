//C5038

#include<stdio.h>

int main()
{
	char c='A';
	int n;
	
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; i++ ){
		
		for(int j=1 ; j<=n+1-i ; j++ ){
			
			if( j==1 ){
				printf("%c", c);
			}else{
				printf(" %c", c);
			}
			c++;
		}
		
		printf("\n");
	}
	
	
	return 0;
}

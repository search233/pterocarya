//C5042

#include<stdio.h>

int main()
{
	int m, n, S=0, flag=0;
	
	scanf("%d %d", &m, &n);
	
	for(int i=m ; i<=n ; i++ ){
		
		S = 0;
		
		for(int j=1 ; j<i ; j++ ){
			
			if( i%j==0 ){
				S += j; 
			}
		}
		
		if( S==i ){
			printf("%d =", S);
			
			for(int j=1 ; j<S ; j++ )
			{
				
				if( j==1 ){
					printf(" %d", j);
				}else if( S%j==0 ){
					printf(" + %d", j);
				}
			}
			printf("\n");
			flag=1;
		}
	}
	
	if( !flag ){
		printf("None");
	}
	
	return 0;
}

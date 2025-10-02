//C5012

#include<stdio.h>

int main()
{
	
	int m, n, chi, rab, i=0;
	
	
	scanf("%d %d", &m, &n);
	
	
	for ( rab=0 ; rab<=m ; rab++)
	{
		
		chi = m - rab;
		
		if(rab*4 == n - chi*2 )
		{
			printf("%d %d", chi, rab);
			
			i = 1;
			
			break;
		}
	}
	
	if( i==0 )
	{
		printf("Error");
	}
	
	return 0;
}

//C5015

#include<stdio.h>
#include<math.h>


int main()
{
	char c;
	int N, i, j;
	
	scanf("%d %c", &N, &c);
	
	for( i=1 ; i<=(int)round(N/2.0) ; i++ ) 
	{
		for( j=1 ; j<=N ; j++ )
		{
			printf("%c", c);
		}
		
		printf("\n");
	}
	
	return 0;
}

//C5017

#include<stdio.h>
#include<math.h>


int count( int x )
{
	int digit=0;
	
	while( x!=0 )
	{
		x /= 10;
		
		digit++;
	}
	
	return digit;
}


int main()
{
	int N, i, num, each;
	
	scanf("%d", &N);
	
	
	if( N<0 )
	{
		printf("fu ");
		N = abs(N);
		
	}else if( N==0 ){
		printf("ling");
	}
	
	
	num = count(N);
		
		
	for( i=num ; i>=1 ; i-- )
	{
		each = N / (int)pow( 10,i-1 );
		
		switch ( each ) 
		{
			case 1: printf("yi"); break;
			case 2: printf("er"); break;
			case 3: printf("san"); break;
			case 4: printf("si"); break;
			case 5: printf("wu"); break;
			case 6: printf("liu"); break;
			case 7: printf("qi"); break;
			case 8: printf("ba"); break;
			case 9: printf("jiu"); break;
			case 0: printf("ling"); break;
		}
		
		if( i>1 ){
			printf(" ");
		}
		
		N %= (int)pow( 10,i-1 );
	}
	
	return 0;
}

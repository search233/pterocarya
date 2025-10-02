//C5014

#include<stdio.h>
#include<math.h>


int digits( int x )
{
	int digit=0;
	
	while( x>0 )
	{
		x /= 10;
		
		digit++;
	}
	
	return digit;
}



int main()
{
	int m, n, i, j=0, num, temp=0;
	
	scanf("%d %d", &m, &n);
	
	for ( i=m ; i<=n ; i++ )
	{
		
		num = pow( i,2 ) - i;
	//printf("%d %d %d\n", num, i, digits(i));
		while( num%10 ==0 )
		{
			
			num /= 10;
			temp++; 

		}
		
		
		if( temp >= digits( i ) )
		{
			//printf("%d\n", digits( i ));
			if( j==0 )
			{
				printf("%d", i);
				j++;
				
			}else{
				printf(" %d", i);	
			}
			
		}
		
		temp =0;
	}
	
	
	if( j==0 ){
		
		printf("No exist");
	}
	

	return 0;
} 


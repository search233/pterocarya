//C5013

#include<stdio.h>

int main()
{
	int m, n, i, flag=0, temp, num;
	
	scanf("%d %d", &m, &n);
	
	for( i=m ; i<=n ; i++ )
	{
		
		if( i%3 == 0)
		{
			num = i; 
		
			while( num > 0)
			{
				
				temp = num % 10;
				
				if( temp == 5)
				{
					if( flag==0 )
					{
						printf("%d", i);
					}else 
					{
						printf(" %d", i);
					}	
					
					flag = 1;
					
					break;
				}else
				{
					num /= 10;
				}
			}
		}
	} 
	
	if( flag == 0 )
	{
		printf("No exist");
	}
	
	
	return 0;
}

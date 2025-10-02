//C5056

#include<stdio.h>

int trans( int x );


int main()
{
	int cnt=0, N, num_1=0, num_0=0;
	
	scanf("%d", &N);
	
	for(int i=1 ; i<N ; i++ ){
		
		int left, temp=i;
		
		while( temp!=0 ){
			
			left = temp % 2;
			
			switch( left ){
				
				case 1:
					num_1++;
					break;
				
				case 0:
					num_0++;
					break;
			}
			
			temp /= 2;
		}
		
		
		if( num_1>num_0 ){
			cnt++;
			//printf("%d\n", i);
		}
		
		num_0 = 0;
		num_1 = 0;	
	}
		
	printf("%d", cnt);
	
	return 0;
} 

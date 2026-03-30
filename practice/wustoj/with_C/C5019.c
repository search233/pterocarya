//C5019

#include<stdio.h>
#include<math.h>


int prime( long x )
{
	for ( long i=2 ; i<x ; i++ )
	{
		if ( x%i==0 ) {
			return 0;
		}
	}
	
	return 1;
}



int main()
{
	long N, A, cnt =0, count=1, start;
	//从A开始，cnt计数 
	//利用count记录最小连续因子，
	//count_max找最长情况 
	
	scanf("%ld", &N);//输入N 
	
	if(prime(!N))
	{
		for ( long i=2 ; i<(long)sqrt(N) ; i++ ){
			
			if( N%i==0 ){		//出现因子后用A迭代并记录次数 
			
				for( long j=i ; j<N ; j++){	
					A = i++;				
					cnt++;
					
					if( N%A==0 ){
						
						count = cnt;
					}else{
						
						count = cnt-1;
						start = A - count; //用start和count定位了最小的连续因子 
						break;
					} 
				}
			}
			
		}
		
		printf("%ld", cnt);
	}else{
		printf("1\n%ld", N); 
	}
	
	return 0;
}

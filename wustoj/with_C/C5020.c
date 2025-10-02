//C5020

#include<stdio.h>

int main()
{
	int N, max=0, min=1000, max_cnt=0, min_cnt=0, temp;
	
	scanf("%d", &N);
	//N = 10;
	for( int i=1 ; i<=N ; i++ ){
		
		scanf("%d", &temp);
		
		
		if( temp>max ){
			max = temp;	
			max_cnt=0;
		}
		if( temp<min ){
			min = temp;
			min_cnt=0;
		}
		if( temp==max ){
			max_cnt++;
		}
		if( temp==min ){
			min_cnt++;
		}
		
	}
	
	printf("%d %d\n%d %d", min, min_cnt, max, max_cnt);
	
	return 0;
}

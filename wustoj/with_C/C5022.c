//C5022

#include<stdio.h>

int main()
{
	int  cnt=1, x, s=0, single=1;
	
	scanf("%d", &x);
	
	if( x==1 ){
		printf("1 1");
		
	}else{
	
		while( single ){
			
			single = single * 10 + 1;
			cnt++;
			
			if( single>=x ){
				s = single / x;
				single = single % x;
				printf("%d", s);
				
			}else if( single<x && s!=0 ){
				printf("0");
			}
			
		}
		
		printf(" %d", cnt);
		
	}
		
	return 0;
}

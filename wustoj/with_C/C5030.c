//C5030

#include<stdio.h>

int main()
{
	int x, fen5, fen2, fen1, sum=0, cnt=0;
	
	scanf("%d", &x);
	
	for( fen5=x/5 ; fen5>=1 ; fen5-- ){
		
		for( fen2=x/2 ; fen2>=1 ; fen2-- ){
			
			for( fen1=x-7 ; fen1>=1; fen1-- ){
				
				if( fen5*5+fen2*2+fen1==x && fen1!=0 && fen2!=0 && fen5!=0 ){
					
					sum = fen5 + fen2 + fen1;
					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, sum);
					cnt++;
				}	
			}
		}	
	} 
	
	printf("count = %d", cnt);
	
	return 0;
}

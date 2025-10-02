//C5043

#include<stdio.h>

int main()
{
	int A, cnt=0;
	
	scanf("%d", &A);
	
	for(int i=A ; i<=A+3 ; i++ ){
		
		for(int j=A ; j<=A+3 ; j++ ){
			
			for(int k=A ; k<=A+3 ; k++ ){
				
				if( i!=j && j!=k && i!=k && i>0 ){
						
					if( cnt==0 ){
						printf("%d%d%d", i, j, k);
						cnt++;
					}else{
						printf(" %d%d%d", i, j, k);
						cnt++;
					}
				
					if( cnt==6 ){
						printf("\n");
						cnt=0;
					}	
					
				
				}
			}
		}
	}
	
	return 0;
} 

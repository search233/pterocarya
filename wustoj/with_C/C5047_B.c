//C5047

#include<stdio.h>


int main()
{
	int X, cnt=0;
	
	scanf("%d", &X);
		
	printf("%d=", X);
		
	for(int i=2 ; ; i++ ){
			
		if( X==i && cnt==1 ){
			printf("*%d", i);
			break;
			
		}else if( X==i && cnt==0 ){
			printf("%d", X);
			break;
		}
			
		if( X%i==0 ){
				
			do{
					
				if( cnt==0 ){
					printf("%d", i);
					cnt=1;
					
				}else{
					printf("*%d", i);
				}
				
				X /= i;
			}while( X%i==0 );
		}
			
	}
	
	return 0;
}

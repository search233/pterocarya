//C5009

#include<stdio.h>

int main(){
	
	int m, n, i, total=0;
	
	scanf("%d %d", &m, &n);
	
	
	for( i=m ; i<=n ; i++ ){
		
		if( i%3==2 && i%5==3 && i%7==4 ){
			
			
			if(total == 0){
				printf("%d", i);
			}else {
				printf(" %d", i);	
			}
			
			total++;	
		}	
	}
	
	
	if( total == 0 ){	
	
		printf("total=%d", total);
	}else{
		
		printf("\ntotal=%d", total);
	}
	
	
	return 0;
}

//C1002

#include<stdio.h>

int main()
{
	int num_1,num_2; 
	
	scanf("%d %d",&num_1,&num_2);			
  
	if( num_1<num_2 ){
		
		printf("max=%d",num_2);

	}else{
		
		printf("max=%d",num_1);
		
	} 
  return 0;
} 

//C6029

#include<stdio.h>

int main()
{
	int emo[24], time=0;
	
	for(int i=0 ; i<24 ; i++){
		scanf("%d", &emo[i]);
	}
	
	scanf("%d", &time);
	
	while( time>=0 && time<=23 ){
		
		printf("%d", emo[time]);
		if(emo[time]>50){
			printf(" Yes\n");
		}else{
			printf(" No\n");
		}
		

		scanf("%d", &time);
	}
	
	return 0;
} 

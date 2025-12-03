//7_9

#include<stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	int list[100];
	for(int i=0 ; i<n ; ++i){
		scanf("%d", list+i);
	}
	
	for(int i=0 ; i<n ; ++i){
		
		int head_l=-1;
		int tmp;
		int gap = (list[i]-1)*2-1;
		
		for(int j=list[i] ; j>0 ; --j){
			
			for(int k=j-1+list[i] ; k>0 ; --k)	printf(" ");
			printf("*");
			for(int k=0 ; k<head_l ; ++k)		printf(" ");
			head_l += 2;
			
			if(j<list[i])	printf("*\n");
			else			printf("\n");
			
		}
		
		for(int j=0 ; j<=list[i] ; ++j)	printf("*"); 
		for(int j=0 ; j<gap ; ++j)		printf(" ");
		for(int j=0 ; j<=list[i] ; ++j)	printf("*");
		printf("\n");
		
		tmp = list[i]-2;
		while(tmp-->0){	
			printf("*");
			for(int j=0 ; j<list[i]*2+gap ; ++j)	printf(" ");
			printf("*\n");
		}
		
		for(int j=0 ; j<=list[i] ; ++j)	printf("*"); 
		for(int j=0 ; j<gap ; ++j)		printf(" ");
		for(int j=0 ; j<=list[i] ; ++j)	printf("*");
		printf("\n");
		
		tmp = list[i];
		while(tmp-->0){
			for(int j=0 ; j<list[i] ; ++j)	printf(" ");	
			printf("*");
			for(int j=0 ; j<gap ; ++j){
				if(tmp>0){
					printf(" ");
				}else{
					printf("*");
				}
			}	
			printf("*\n");
		}
		
		printf("\n");
	}
	
	return 0;
}

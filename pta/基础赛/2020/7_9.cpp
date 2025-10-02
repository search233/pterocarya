//7_9

#include<stdio.h>

int main()
{
	int T;	scanf("%d", &T);
	int n[100];
	
	for(int i=0 ; i<T ; i++){
		scanf("%d", n+i);
	}
	
	for(int l=0 ; l<T ; l++){
		int temp = n[l];
		
		//part_1 
		for(int i=1 ; i<temp ; i++){
			int j;
			for(j=temp-i ; j>=1 ; j--)	printf(" ");
			printf("*");
			for(j=0 ; j<i-2 ; j++)		printf(" ");
			if(i>1)	printf("*");
			for(j=0 ; j<temp ; j++)		printf(" ");
			printf("*");
			for(j=0 ; j<i-2 ; j++)		printf(" ");
			if(i>1)	printf("*\n"); else printf("\n");
		}
		
		//part_2
		for(int i=0 ; i<temp*3 ; i++)	printf("*");
		printf("\n");
		
		//part_3
		for(int i=0 ; i<temp-2 ; i++){
			printf("*");
			for(int j=0 ; j<temp*3-2 ; j++)	printf(" ");
			printf("*\n");
		}
		
		//part_4
		for(int i=0 ; i<temp*3 ; i++)	printf("*");
		printf("\n");
		
		printf("\n");
	}
	
	return 0;
}

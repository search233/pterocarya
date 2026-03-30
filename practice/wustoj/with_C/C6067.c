//C6067

#include<stdio.h>

int main()
{
	int n, cnt=2;	scanf("%d", &n);
	int fib[500] = {1,};
	int fib_1[500] = {1,};
	int temp[500] = {0}; 
	int tag;
	
	while(cnt!=n && n>2){
		
		for( tag=499 ; fib[tag]==0 ; tag--);
		
		for(int i=0 ; i<=tag ; i++){
			temp[i] = fib[i];
		}
		
		for(int i=0 ; i<=tag; i++){

			fib[i] += fib_1[i];	
			fib[i+1] += fib[i]/10;		
			fib[i] %= 10;
			
			if(fib[tag+1]){
				tag++;
			}
		}
		
		for(int i=0 ; i<=tag ; i++){
			fib_1[i] = temp[i];
		}
		
		cnt++;
	}

	for( tag=499 ; fib[tag]==0 ; tag--);
	
	if(n==1 || n==2){
		printf("%d", 1);
	}else{
		for(int i=tag ; i>=0 ; i--){
			printf("%d", fib[i]);
		} 
	}
	
	return 0;
} 

//C6002

#include<stdio.h>

int main()
{
	int n, cnt=0;
	
	scanf("%d", &n);
	
	int fib[40] = { 1, 1};
	
	for(int i=2 ; i<n ; i++ ){
		fib[i] = fib[i-1] + fib[i-2];
	}
	
	for(int i=0 ; i<n ; i++ ){
		
		printf("%10d", fib[i]);
		cnt++;
		
		if(cnt==5){
			printf("\n");
			cnt=0;
		}
		
	}
	
	return 0;
}

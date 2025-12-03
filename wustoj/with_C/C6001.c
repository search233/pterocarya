//C6001

#include<stdio.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	
	int N[n];
	
	for(int i=0 ; i<n ; i++){
		scanf("%d", &N[i]);
	}
	
	for(int i=n-1 ; i>=0 ; i-- ){
		if( i==n-1 ){
			printf("%d", N[i]);
		}else{
			printf(" %d", N[i]);		
		}
	}
	
	return 0;
}

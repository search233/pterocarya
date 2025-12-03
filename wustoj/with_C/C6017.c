//C6017

#include<stdio.h>


int main()
{
	int n, A[101], x;
	
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++ ){
		scanf("%d", &A[i]);
	}
	scanf("%d", &x);
	
	for(int i=0 ; i<n ; i++ ){
		A[i] = A[i+1];
		if(x<A[i]){
			A[i] = x;
			break;
		}
		if(i==n-1 && x>A[n]){
			A[n] = x;
		}
	}
	
	for(int i=0 ; i<=n ; i++){
		if(i==0){
			printf("%d", A[i]);
		}else{
			printf(" %d", A[i]);
		}
	}
	
	return 0;
}

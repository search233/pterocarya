//C6049

#include<stdio.h>

int main()
{
	int n, m=0;
	scanf("%d", &n);
	
	n *= 2;
	
	int A[n];
	
	for(int i=1 ; i<=n ; i++){
		A[i] = i;
	}
	
	while(1){
		int B[n];
		
		for(int i=1 ; i<=n ; i++){
			if(i%2){
				B[(i+n+1)/2] = A[i];
			}else{
				B[i/2] = A[i];
			}
		}
		
		for(int i=1 ; i<=n ; i++){
			A[i] = B[i];
		}
		m++;
		for(int i=1 ; i<=n ; i++){
			if(A[i]!=i){
				break;
			}
			if(i==n){
				printf("%d", m);
				return 0;
			}
		}
	}
}

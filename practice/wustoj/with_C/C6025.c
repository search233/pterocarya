//C6025

#include<stdio.h>

int main()
{
	int n, S1=0, S2=1;
	int N[31][31];
	
	scanf("%d", &n);
	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			scanf("%d", &N[i][j]);
		}
	}
	
	for(int i=0, j=0 ; i<n ; i++, j++){
		S1 += N[i][j];
		if(i%2==0 && j%2==0){
			S2 *= N[i][j];
		}
	}
	
	for(int i=0, j=n-1 ; j>=0 ; i++, j--){
		S1 += N[i][j];
		if(i%2==0 && j%2==0){
			S2 *= N[i][j];
		}
	}	
	
	if(n%2){
		int x=(n-1)/2;
		S1 -= N[x][x];
	}
	
	printf("%d %d\n", S1, S2);
	
	for(int j=0 ; j<n ; j++){
		for(int i=n-1 ; i>=0 ; i--){
			if(i==n-1){
				printf("%d", N[i][j]);
			}else{
				printf(" %d", N[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}

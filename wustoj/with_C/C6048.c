//C6048

#include<stdio.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	
	int A[n+2];
	
	for(int i=1 ; i<=n ; i++){
		scanf("%d", &A[i]);
	}
	
	int B[n+1][n+1], cnt=1, tag=1, temp;
	
	for(int i=1 ; i<=n ; i++){
		while(i!=A[cnt]){
			cnt++;
		}
		while(cnt!=A[tag]){
			tag++;
		}
		
		for(int j=1 ; j<=n ; j++){
			temp = A[tag];
			B[j][temp] = i;
			if(tag==n){
				tag = 1; 
			}else{
				tag++;
			}
		}
		tag = 1;
		cnt = 1;
	}
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(j==1){
				printf("%d", B[i][j]);
			}else{
				printf(" %d", B[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}

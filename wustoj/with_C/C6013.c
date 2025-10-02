//C6013

#include<stdio.h>

int main()
{
	int num[101][101] = { 0,};
	int n;

	scanf("%d", &n);
	
	num[1][(n+1)/2] = 1;
	
	int i=1, j=(n+1)/2;
	
	int sum = n*n;
	
	for(int k=2 ; k<=sum ; k++){
		int temp_i=i, temp_j=j;
		
		i--; j++;
		
		if(i==0){
			i = n;
		}
		if(j==n+1){
			j = 1;
		}
		
		if(num[i][j]!=0){
			i = temp_i + 1;
			j = temp_j;
		}
		
		num[i][j] = k;
	}
	
	for (i=1 ; i<=n ; i++){
		for(j=1 ; j<=n ; j++){
			printf("%4d", num[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

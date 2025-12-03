//C6014

#include<stdio.h>

int main()
{
	int m, n;
	int score[200][20] = {0,};
	char name[200][100];
	
	scanf("%d %d", &n, &m);
	
	for(int i=1 ; i<=n ; i++ ){
		
		scanf("%s", name[i]);
		
		for(int j=1 ; j<=m ; j++ ){
			scanf("%d", &score[i][j]);
			score[i][0] += score[i][j];
			score[0][j] += score[i][j];
		}
	}
	
	for(int i=1 ; i<=n ; i++ ){

		printf("%-8s", name[i]);
		
		for(int j=0 ; j<=m ; j++ ){
			printf("%6d", score[i][j]);
			
		}
		
		printf("\n");
	}
	
	double aver[20] = {0,};
	for(int j=1 ; j<=m ; j++ ){
		aver[j] = score[0][j] / (double)n;
	}
	
	printf("average score:");
	for(int j=1 ; j<=m ; j++ ){
		printf("%6.1f", aver[j]);
	}
	
	return 0;
}

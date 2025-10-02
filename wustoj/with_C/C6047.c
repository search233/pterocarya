//C6047

#include<stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	getchar();
	N = 2*N;
	
	char Game[50][50];
	
	for(int i=1 ; i<=N ; i++){
		for(int j=1 ; j<=N ; j++){
			scanf("%c ", &Game[i][j]);
		}
	}
	
	int K;
	scanf("%d", &K);
	
	int x1, y1, x2, y2;
	int error_cnt=0;
	int correct_cnt=0;
	
	while(K){
		
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		if(Game[x1][y1]==Game[x2][y2] && Game[x1][y1]!='*'){
			Game[x1][y1] = '*';
			Game[x2][y2] = '*';
			correct_cnt++;
			
			if(correct_cnt==N*N/2){
				printf("Congratulations!");
				return 0;
			}
			
			for(int i=1 ; i<=N ; i++){
				for(int j=1 ; j<=N ; j++){
					if(j==1){
						printf("%c", Game[i][j]);
					}else{
						printf(" %c", Game[i][j]);
					}
				}
				printf("\n");
			}
		
			
		}else{
			error_cnt++;
			printf("Uh-oh\n");
		}
		
		if(error_cnt==3){
			printf("Game Over");
			return 0;
		}		
		K--; 
	}
	
	return 0;
} 

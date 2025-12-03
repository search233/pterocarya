 //C6069
 
#include<stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	int queue[n][n];
	int cnt=1;

	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			queue[i][j] = cnt++;
		}
	}

	
	for(int j=0 ; j<n ; j++){
		int x;
		
		for(int i=n-1 ; i>=0 ; i--){
			
			if(i%2==0){
				x = n-1-j;
			}else{
				x = j;
			}
			
			printf("%5d", queue[i][x]);
		}

		printf("\n");
	}
	
	return 0;
}

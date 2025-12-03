//P1002

#include<stdio.h>

int main(){
	long long point[40][40] = {1,};
	
	int hx[9] = {0,-2,-1, 1, 2, 2, 1,-1,-2};
	int hy[9] = {0,-1,-2,-2,-1, 1, 2, 2, 1};
	
	int n, m, x, y;	
	scanf("%d %d %d %d", &n, &m, &x, &y);

	
	for(int i=0 ; i<=n ; i++){
		for(int j=0 ; j<=m ; j++){
			point[i][j] = 1;
		}
	}
	
	
	for(int i=0 ; i<9 ; i++){
		if((x+hx[i]>=0 && x+hx[i]<=n) && (y+hy[i]>=0 && y+hy[i]<=m)){
			point[x+hx[i]][y+hy[i]] = 0;
		}
	}
	
	for(int i=0 ; i<=m ; i++){
		if(point[0][i]==0){
			for( ; i<=m ; i++){
				point[0][i] = 0;
			}
		}
	}
	for(int i=0 ; i<=n ; i++){
		if(point[i][0]==0){
			for( ; i<=n ; i++){
				point[i][0] = 0;
			}
		}
	}
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			if(point[i][j])	
			point[i][j] = point[i-1][j] + point[i][j-1];
		}
	}
	
	printf("%lld", point[n][m]);
	
	return 0;
}

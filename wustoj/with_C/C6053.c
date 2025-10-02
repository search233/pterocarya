//C6053

#include<stdio.h>

int main()
{
	int m, n;	scanf("%d %d", &m, &n);
	int status[21][21] = {0};
	char map[21][21];
	
	getchar();
	
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			map[i][j] = getchar();
			
			if(map[i][j]=='#'){
				status[i][j] = 2;
			}
		}
		getchar();
	}
	
	
	
	int k;	scanf("%d", &k);
	int x, y, cnt=0;
	
	for(int i=0 ; i<k ; i++)
	{
		scanf("%d %d", &x, &y);
		
		if(map[x][y]=='#'){
			map[x][y] = '0';
			cnt++;
			status[x][y] = 0;
		}
		
		if(map[x+1][y]=='#'){
			status[x+1][y]--;
			if(status[x+1][y]==0){
				cnt++;
				map[x+1][y]='0';
			}
		}
		if(map[x][y+1]=='#'){
			status[x][y+1]--;
			if(status[x][y+1]==0){
				cnt++;
				map[x][y+1]='0';
			}
		}
		if(map[x-1][y]=='#'){
			status[x-1][y]--;
			if(status[x-1][y]==0){
				cnt++;
				map[x-1][y]='0';
			}
		}
		if(map[x][y-1]=='#'){
			status[x][y-1]--;
			if(status[x][y-1]==0){
				cnt++;
				map[x][y-1]='0';
			}
		}
		
		printf("%d\n", cnt);
		cnt=0;
	}
	
	return 0;
}

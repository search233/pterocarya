//C6034

#include<stdio.h>
#include<string.h>

int main()
{
	int n, m, len, cnt=0;
	char put[101][101] = {' '};
	char in[1001];
	
	scanf("%d", &n);
	getchar();
	gets(in);
	
	len = strlen(in);
	
	if(len%n){
		m = len / n + 1;
	}else{
		m = len / n;
	}
	
	for(int j=m-1 ; j>=0 ; j--){
		
		for(int i=0 ; i<n ; i++){
			
			if(cnt<len){
				put[i][j] = in[cnt];
				cnt++;	
			}else{
				put[i][j] = ' ';
			}
		}
	}
	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			printf("%c", put[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

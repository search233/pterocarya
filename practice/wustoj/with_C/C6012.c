//C6012

#include<stdio.h>

int main()
{
	int n, m, s, cnt=0;
	
	scanf("%d %d %d", &n, &m, &s);
	
	int man[101] = {0}, out[100] = {0};
	int count = 1;
	int i=s;
	
	if( m==1 ){
		count = 0;
		i = 0;
	} 
	
	while(cnt<n){
		i++;
		
		if( i>n ){
			i -= n;
		}
		
		if( man[i]==0 ){
			count++;
			
			if( count>=m ){
				man[i] = 1;
				out[cnt++] = i;
				count = 0;
			}
		}
	} 

	
	for(int i=0 ; i<n ; i++){
		printf("%3d", out[i]);
	}
	
	return 0;
}

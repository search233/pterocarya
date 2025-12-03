//C6023

#include<stdio.h>

int main()
{
	int n, m;
	int hole[101] = {0,};
	int i=0, cnt=1, flag=0;
	
	scanf("%d %d", &n, &m);
	
	while(m){
		hole[i] = 1;
		i += cnt+1;
		cnt++;
		if(i>=n){
			i %= n;
			m--;
		}
	}
	
	for(int i=0 ; i<n ; i++){
		
		if(!hole[i]){
			if(!flag){
				printf("%d", i+1);
				flag=1;
			}else{
				printf("% d", i+1);
			}
		}
	}
	
	if(!flag){
		printf("No choice");
	}
	
	return 0;
}

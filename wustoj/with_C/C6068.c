//C6068

#include<stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	int vote, column[8] = {0,};
	
	for(int i=0 ; i<n ; i++){
		scanf("%d", &vote);
		if(vote!=-1){
			column[vote-1]++;
		}
	}
	
	for(int i=0 ; i<8 ; i++){
		printf("%d %d\n", i+1, column[i]);
	}
	
	return 0;
}

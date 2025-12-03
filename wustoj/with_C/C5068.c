//C5068

#include<stdio.h>

int sum(int x)
{
	int S=0, temp;
	
	while(x!=0){
		temp = x % 10;
		
		S += temp;
		
		x /= 10;
	}
	
	return S;
}


int main()
{
	int N, flag=0, cnt=0;
	
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; i++){
		
		if( sum(i)==15 ){
			
			printf("%6d", i);
			cnt++;
			flag = 1;
		}
		
		if(cnt==8){
			printf("\n");
			cnt=0;
		}
	}
	
	if( flag==0 ){
		printf("None");
	}
	
	return 0;
}

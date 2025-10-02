//C6016

#include<stdio.h>

int main()
{
	int N;
	int num[10001];
	
	scanf("%d", &N);
	
	for(int i=2 ; i<=N ; i++ ){
		
		if(i!=2 && i%2==0 ){
			num[i] = 0;
		}else{
			num[i] = 1;
		}
	}
	
	for(int i=3 ; i<=N ; i+=2 ){
		
		if(num[i]==1){ 
			for(int j=2 ; j*i<=N ; j++ ){
				num[i*j] = 0; 
			} 
		}
	}
	
	for(int i=2 ; i<=N ; i++ ){
		if(i==2){
			printf("%d", i);
		}else if(num[i]==1){
			printf(" %d", i);
		}
	}
	
	return 0;
}

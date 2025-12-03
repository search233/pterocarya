//7_5

#include<stdio.h>

int main(){
	
	int t;	scanf("%d", &t);
	bool judge[11];
	
	for(int i=0 ; i<t ; i++){
		int n;	scanf("%d", &n);
		int temp;
		double sum=0;
		
		for(int j=0 ; j<n ; j++){
			scanf("%d", &temp);
			sum += temp;
		}
		
		if(sum/n>0.75){
			judge[i] = true;
		}else{
			judge[i] = false;
		}
	}
	
	for(int i=0 ; i<t ; i++){
		if(judge[i]){
			printf("WWtql!");
		}else{
			printf("WWtcl!");
		}
		printf("\n");
	}
	
	return 0;
}

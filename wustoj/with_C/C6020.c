//C6020

#include<stdio.h>

int main()
{
	int n, temp;
	
	scanf("%d", &n);
	
	int num[100] = {0};
	
	for(int i=0 ; i<n ; i++ ){
		scanf("%d", &num[i]);
	}
	
	for(int j=1 ; ; j++){
		
		int cnt=0;
		
		for(int i=1 ; i<n ; i++ ){
		
			if( num[i] < num[i-1] ){
				temp = num[i];
				num[i] = num[i-1];
				num[i-1] = temp;
				cnt=1;
			}	
		}
		
		if(cnt==0){
			for(int i=0 ; i<n ; i++){
				
				if(num[i]%2==1){
					if(cnt==0){
						printf("%d", num[i]);
						cnt=1;
					}else{
						printf(" %d", num[i]);
					}
				}
			}
			
			for(int i=0 ; i<n ; i++){
				if(num[i]%2==0){
					printf(" %d", num[i]); 
				}
			}
			break;
		}
	}
	
	return 0;
}

//C6004(C6019)

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
			
			for(int i=0 ; i<n ; i++ ){
				
				if(i==0){
					printf("%d", num[i]);
				}else{
					printf(" %d", num[i]);
				}
			}		
			
			break;
		}
	}
	
	return 0;
}

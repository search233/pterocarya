//C6052

#include<stdio.h>

int main()
{
	int num[1001] ={0};
	int sum=0, tag=1, max;
	
	int n;  scanf("%d", &n); 
	
	for(int i=0 ; i<n ; i++){
		scanf("%d", &num[i]);
	}
	
	for(int i=0 ; i < n ; i++){
		for(int j=0 ; j<4 ; j++){
			if(i+j>n){
				sum += num[i+j-n];
			}else{
				sum += num[i+j];
			}
		}
		
		if(i==0){
			max = sum;
		}else if(sum>max){
			max = sum;
			tag = i+1;
		}
		
		sum = 0;
	}
	
	printf("%d %d", max, tag);
	
	return 0;
}

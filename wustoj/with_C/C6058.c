//C6058

#include<stdio.h>

int main()
{
	int num[11] = {0}, n, sum=0;
	
	scanf("%d", &n); 
	
	for(int i=0 ; i<n ; i++){
		scanf("%d", &num[i]);
	}
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(i==j){
				j++;
			}
			if(j==n){
				break;
			}
			
			sum += num[i]*10 + num[j];
		}
	}
	
	printf("%d", sum);
	
	return 0;
}

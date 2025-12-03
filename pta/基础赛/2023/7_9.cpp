//7_9

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;	scanf("%d", &n);
	
	for(int i=0 ; i<n*3 ; i++)	printf("*");
	for(int i=0 ; i<n ; i++)	printf(" ");
	for(int i=0 ; i<n*3 ; i++)	printf("*");
	printf("\n");
	
	int cnt;
	for(int i=2-n ; i<=n-2 ; i++){
		
		if(i==2-n)					cnt=n/2-1;
		else if(i>2-n && i<1-n+n/2)	cnt--;
		else if(i==n-n/2)			cnt=1;
		else if(i>=n-n/2)			cnt++;
		
		for(int j=0 ; j<=n-2-abs(i) ; j++)	printf(" ");
		printf("*");
		
		for(int j=0 ; j<7*n-2*(n-abs(i)) ; j++){		
			
			if(i>=2-n && i<1-n+n/2 && (j==3*n-2 || j==3*n-1+cnt*2)){
				printf("*");	
			}else if(i>n-1-n/2 && i<=n-2 && (j==3*n-2 || j==3*n-1+cnt*2)){
				printf("*");
			}else{
				printf(" ");
			}
		}	
		printf("*\n");
	}
	
	
	for(int i=0 ; i<n*3 ; i++)	printf("*");		
	for(int i=0 ; i<n ; i++)	printf(" ");
	for(int i=0 ; i<n*3 ; i++)	printf("*");
	printf("\n");
	
	return 0;
}

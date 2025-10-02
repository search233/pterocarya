//C6005

#include<stdio.h>

int f(int num[], int n, int x)
{
	int A = 0, B = n-1;

	while( B >= A ){
		
		int mid = (A+B) / 2;	
			
		if( num[mid] > x ){
			B = mid - 1;
		}else if( num[mid] < x ){
			A = mid + 1;
		}else{
			return mid;
		}
	}
	
	
	return -1;
}


int main()
{
	int n, num[100] = {0,}, x;
	
	scanf("%d", &n);
	
	for(int i=0 ; i<n ; i++ ){
		scanf("%d", &num[i]);
	}
	
	scanf("%d", &x);
	
	int temp;
	
	temp = f( num, n, x);
	
	if( temp==-1 ){
		printf("Not found");
	}else{
		printf("%d", temp);
	}
	
	return 0;
}

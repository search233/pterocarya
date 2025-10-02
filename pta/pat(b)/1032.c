//1032

#include<stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	int a[100100]={0,};
	int max=0, school_max;
	int schID, score;
	
	
	for(int i=0 ; i<n ; i++){
		scanf("%d %d", &schID, &score);
		a[schID] += score;
	}
	
	for(int i=1 ; i<=n ; i++){
		if(a[i]>=max){
			max = a[i];    
			school_max = i;
		}
	}
	
	printf("%d %d", school_max, max);
	
	return 0;
}

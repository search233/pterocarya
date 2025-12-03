//C5004

#include<stdio.h>

int main()
{
	int n, judge = 1, i;
	
	scanf("%d", &n);
	
	for( i=2 ; i<n ; i++ ){
		if( n%i == 0 ){
			judge = 0;
			break;
		}
	}
	
	if(judge == 1 && n != 1){
		printf("YES");
	}else{
		printf("NO");
	}
	
	return 0;
}

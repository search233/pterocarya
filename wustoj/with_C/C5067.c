//C5067

#include<stdio.h>

int sum(int x){
	
	int S=0;
	
	for(int i=1 ; i<x ; i++ ){
		
		if( x%i==0 ){
			S += i;
		}
	}
	
	return S;
}


int main()
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	if( a==sum(b) && b==sum(a) ){
		printf("YES");
	}else{
		printf("NO");
	}
	
	return 0;
}

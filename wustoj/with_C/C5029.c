//C5029

#include<stdio.h>

int prime(int x){
	
	int out=1;
	
	for(int i=2 ; i<x ; i++ ){
		
		if( x%i==0 ){
			out = 0;
		}
	}
	
	if( x==1 ){
		out = 0;
	}
	
	return out;
}

int main()
{
	int S=0, cnt=0, M, N; 
	
	scanf("%d %d", &M, &N);
	
	for (int i=M ; i<=N ; i++ ){
		
		//printf("%d %d\n", i, prime(i));
		
		if( prime(i) )
		{
			cnt++;
			S += i;
		}
	}
	
	printf("%d %d", cnt, S);
	
	return 0;
}

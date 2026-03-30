//C5023

#include<stdio.h>

int factorial( int x ){
	
	int out=1;
	
	for (int i=1 ; i<=x ; i++ ){
		out *= i;
	}
	
	return out;
}

int main(){
	
	int N, S=0;
	
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; i++ ){
		S += factorial(i);
	}
	
	printf("%d", S);
	
	return 0;
}

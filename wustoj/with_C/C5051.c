//C5051

#include<stdio.h>

int F( int x );


int main()
{
	int N[100];
	
	scanf("%d", &N[0]);
	
	for(int i=1 ; ; i++ ){
		
		N[i] = F( N[i-1] );
		
		printf("%d:%d\n", i, N[i]);
		
		if( N[i]==N[i-1] ){
			break;
		}
	}	
	
	return 0;
} 



int F( int x )
{
	int A[100], S=0, result;
	
	for(int i=0 ; i<=100 ; i++ ){
		
		A[i] = x % 10;
		
		S += A[i]; 
		
		x /= 10;
		
		if( x==0 ){
			result = S * 3 + 1;
			break;
		}
		
	}
	
	return result;
}

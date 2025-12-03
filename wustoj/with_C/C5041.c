//C5041

#include<stdio.h>
#include<math.h>

int pow_2n( int x ){
	int result=1;
	for(int i=0 ; i<x ; i++ ){
		result *= 2;
	}
	return result;
}

int prime( int x ){
	for(int i=2 ; i<=(int)sqrt(x) ; i++ ){	
		if( x%i==0 ){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, temp, cnt=0; 
	scanf("%d", &n);
	for(int i=2 ; i<=n ; i++ ){	
		temp = pow_2n(i) - 1;
		if( prime(temp) ){
			printf("%d\n", temp);
			cnt++;
		}
	}	
	if( cnt==0 ){
		printf("None");
	}
	return 0;
}

//C5025

#include<stdio.h>

int main()
{
	int N;
	double S=0;
	
	scanf("%d", &N);
	
	for (int i=1 ; i<=N*3-2 ; i+=3 ){
		
		if( i%2!=0 ){
			S += 1.0 / i;
	
		}else{
			S -= 1.0 / i; 
		}
	}
	
	printf("%.4f", S);
	
	return 0;
}

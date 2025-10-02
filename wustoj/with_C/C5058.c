//C5058

#include<stdio.h>

int main()
{
	int N, A1=0, A2=0, A3=0;
			
	double S=0;
	
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; i++ ){
		
		int n;
		
		scanf("%d", &n);
		
		if( n%3==0 && n>A1 ){
			A1 =  n;
		}else if( (n-1)%3==0 ){
			A2++;
		}else if( (n-2)%3==0 ){
			A3++;
			S += n;
		}
	}
	
	S /= A3;
	
	if( !A1 ){
		printf("NONE ");
	}else{
		printf("%d ", A1);
	}
	
	if( !A2 ){
		printf("NONE ");
	}else{
		printf("%d ", A2);
	}
		
	if( !A3 ){
		printf("NONE");
	}else{
		printf("%.1f", S);
	}
			
			
	return 0;
}

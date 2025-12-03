//C5065

#include<stdio.h>

long long trans(long long x)
{
	long long temp, result=0;
	
	
	while(x!=0){
		
		temp = x % 10;
		
		result = result * 10 + temp;
		
		x /= 10;
	}
	
	return result;
}

int main()
{
	long long N;
	
	int cnt=0;
	
	scanf("%lld", &N);
	
	printf("%lld", N);
	
	if(N==trans(N)){
		printf("\n%d", cnt);
		
	}else{
		
		do{
			
			N += trans(N);
			printf("--->%lld", N);
			cnt++;
			
		}while( N!=trans(N) );
		
		printf("\n%d", cnt);
		
	}
	
	
	return 0;
}

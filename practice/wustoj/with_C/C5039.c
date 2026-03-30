//C5039

#include<stdio.h>

int main()
{
	int N, S=0, cnt=0, temp;
	
	scanf("%d", &N);
	
	for(int i=1 ; ; i++ )
	{
		if( N!=0 ){
			
			temp = N % 10;
			S += temp;
			
			N /= 10;
			cnt++;
		}else{
			break;
		}
	}
	
	printf("%d %d", cnt, S);
	
	return 0;
}

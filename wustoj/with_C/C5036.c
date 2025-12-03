//C5036

#include<stdio.h>

int main()
{
	int N, cnt=1, S=1, temp=0, An=1;
	
	scanf("%d", &N);
	
	for(int i=1 ; ; i++ ){
		
		if( S>=N ){
			break;
			
		}else{
			cnt++;
			
			temp = S;
			S += An;
			An = temp;
		}
	}
	if( N==1 ){
		printf("%d", cnt);
	}else{
		printf("%d", cnt+1);
	}
	
	return 0;
} 

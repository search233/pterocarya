//C6036

#include<stdio.h>

int judge(int n, int y);


int main()
{
	int y, x, n;
	
	scanf("%d %d", &y, &n);
	
	for( x=0 ; ; x++){
		if(judge(n, x+y)==1){
			break;
		}
	}
	
	printf("%d %04d", x, x+y);
	
	return 0;
}


int judge(int n, int y)
{
	int ret=0, Y[10] = {0,};

	
	for(int i=0 ; i<4 ; i++){
		
		if(Y[y%10]==0){
			ret++;
		}
		Y[y%10]++;
		y /= 10;
	}
	
	if(n==ret){
		return 1;
	}
	
	return 0;
}

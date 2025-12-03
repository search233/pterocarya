//1022

#include<stdio.h>

int main()
{
	long a, b, d;	scanf("%ld %ld %ld", &a, &b, &d);
	long sum = a + b;
	int cnt=0;
	int c[10000] = {0,};
	
	do{
		c[cnt++] = sum % d;
		sum /= d;
	}while(sum);
	cnt--;
	
	for( ; cnt>=0 ; cnt--){
		printf("%d", c[cnt]);
	}
	
	return 0;
}

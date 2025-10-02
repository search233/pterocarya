//C5028

#include<stdio.h>

double f(int x){
	double out=1;
	
	for (int i=1 ; i<=x ; i++ ){
		out *= (double)i;
	}
	
	return out;
}

int main()
{
	int n;
	double e=1;
	
	scanf("%d", &n);
	
	for (int i=1 ; i<=n ; i++ ){
		e += 1/f(i);
	}
	
	printf("%.8f", e);
	
	return 0;
}

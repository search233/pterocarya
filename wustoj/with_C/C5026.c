//C5026

#include<stdio.h>

double f( int x ){
	double out=1;
	
	for (int i=1 ; i<=x ; i++ ){
		out *= (double)i;
	}
	
	return out;
}

int main()
{
	int m, n;
	double C;
	
	scanf("%d %d", &m, &n);
	
	C = f(n) / (f( n-m ) * f(m)) ;
	
	printf("%.0f", C);
	
	return 0;
}

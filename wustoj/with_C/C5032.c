//C5032

#include<stdio.h>
#include<math.h>

double A( double x,int n){
	double out, fac=1;
	
	for(int i=1 ; i<=n ; i++ ){
		fac *= i;
	}
	
	out = pow(x,n) / fac;
	
	return out;
}


int main()
{
	double x, ex=1, An;
	
	scanf("%lf", &x);
	
	for(int i=1 ; ; i++ ){
		An = A(x,i);
		ex += An;
		if( An<0.000001 ){
			break;
		}
	}
	
	printf("%.5f", ex);
	
	return 0;
	
}

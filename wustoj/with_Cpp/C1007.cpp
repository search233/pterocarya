//C1007

#include<iostream>
#include<cstdio>
#define PI 3.14
using namespace std;

int main(){
	double r;	scanf("%lf", &r);
	
	double S = PI * r * r;
	double C = 2 * PI * r;
	
	printf("%.6f\n%.6f", S, C);
	
	return 0;
}

//7_8

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define PI 3.14159

bool judge(double a, double b, double c);

int main()
{
	double a, b, c, P;
	
	int T;	scanf("%d", &T);
	
	for(int i=0 ; i<T ; i++){
		
		scanf("%lf %lf %lf", &a, &b, &c);
		P = (a+b+c)/2;
		
		if(judge(a,b,c)){
			double r = sqrt(P*(P-a)*(P-b)*(P-c)) / P;
			printf("%.2f\n", PI*r*r);
		}else{
			printf("Oh my god!!\n");
		}
	}
	
	return 0;
}

bool judge(double a, double b, double c){
	bool ret = false;
	if(a+b>c && a+c>b && b+c>a)	ret=true;
	return ret;
}

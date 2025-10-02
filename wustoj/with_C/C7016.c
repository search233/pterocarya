//C7016

#include<stdio.h>

int judge(int);

int main()
{
    int n;
    scanf("%d",&n);
    if(judge(n))  printf("YES\n");
    else printf("NO\n");
    return 0;
}

int judge(int n){
	int a=n/100;
	int b=n%10;
	int c=n%100/10;
	
	int fac = a*a*a + b*b*b + c*c*c;
	
	return fac==n ? 1 : 0;
}

//C7008

#include<stdio.h>

int gcd(int,int);

int main()
{
    int a,b,x;
    scanf("%d%d",&a,&b);
    x=gcd(a,b);
    printf("%d\n",x);
    return 0;
}

int gcd(int m, int n){
	return n==0 ? m : gcd(n,m%n);
}

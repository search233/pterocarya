//C7007

#include<stdio.h>

int fac(int);

int main()
{
    int n,y;
    scanf("%d",&n);
    y=fac(n);
    printf("%d!=%d\n",n,y);
    return 0;
}

int fac(int n){
	return n==0 ? 1 : fac(n-1)*n;
}

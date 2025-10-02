//C7009

#include<stdio.h>

int fun(int,int);

int main()
{
    int m,n,x;
    scanf("%d%d",&m,&n);
    x=fun(m,n);
    printf("%d\n",x);
    return 0;
}

int fun(int m, int n) {
	return (n==0 || n==m) ? 1 : fun(m-1,n-1) + fun(m-1,n);
}

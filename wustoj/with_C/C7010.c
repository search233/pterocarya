//C7010

#include<stdio.h>

int fib(int);

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",fib(n));
    return 0;
}

int fib(int n) {
  return (n==0 || n==1) ? 1 : fib(n-1) + fib(n-2);
}

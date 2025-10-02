//C7020

#include<stdio.h>

int digit(int,int);

int main()
{
    int n,k,ans;
    scanf("%d%d",&n,&k);
    ans=digit(n,k);
    printf("%d\n",ans);
    return 0;
}

int digit(int n,int k){
	int cnt=-1, list[10]={0};
	while(n){
		list[++cnt] = n%10;
		n /= 10;
	}
	if(k>cnt+1) return -1;
	else return list[k-1];
}

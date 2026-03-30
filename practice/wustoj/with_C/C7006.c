//C7006

#include<stdio.h>
int max(int a,int b,int c);
int main()
{
    int a,b,c,d;
    scanf("%d%d%d",&a,&b,&c);
    d=max(a,b,c);
    printf("max(%d,%d,%d)=%d\n",a,b,c,d);
    return 0;
}

int max(int a,int b,int c){
	
	int res;
	if(a>=b && a>=c) res=a;
	else if(b>=a && b>=c) res=b;
	else if(c>=a && c>=b) res=c;
	
	return res;
}

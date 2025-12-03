//C7019

#include<stdio.h>
int DaysOfYear(int,int,int);
int main()
{
    int year,month,day,ans;
    scanf("%d%d%d",&year,&month,&day);
    ans=DaysOfYear(year,month,day);
    printf("%d\n",ans);
    return 0;
}

int DaysOfYear(int y ,int m ,int d){
	int M[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((y%4==0 && y%100!=0)|| y%400==0) M[2]=29;
	
	int res=d;
	for(int i=1 ; i<m ; ++i) res += M[i];
	
	return res;
}

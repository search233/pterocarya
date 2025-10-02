//C7012

#include<stdio.h>

double average(int[],int);

int main()
{
    double ave;
    int n,i,score[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&score[i]);
    ave=average(score,n);
    printf("average score is %.2lf\n",ave);
    return 0;
}

double average(int a[],int n) {
	double res=0;
	
	for(int i=0 ; i<n ; ++i){
		res += a[i];
	}
	
	return res / n;
}

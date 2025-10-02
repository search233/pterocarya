//C7015

#include<stdio.h>

int BinSearch(int[],int,int);

int main()
{
    int a[100],n,i,x,index;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&x);
    index=BinSearch(a,n,x);
    if(index<0)
        printf("Not found\n");
    else printf("%d\n",index);
    return 0;
}




int BinSearch(int num[], int n, int x)
{
	int A = 0, B = n-1;

	while( B >= A ){
		
		int mid = (A+B) / 2;	
			
		if( num[mid] < x ){
			B = mid - 1;
		}else if( num[mid] > x ){
			A = mid + 1;
		}else{
			return mid;
		}
	}
	
	return -1;
}

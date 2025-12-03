//C7013

#include<stdio.h>

void print(int[],int);
void sort(int[],int);

int main()
{
    int a[100]={0,},n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Before sort:\n");
    print(a,n);           //输出排序前的数组元素
    sort(a,n);            //冒泡排序
    printf("After sort:\n");
    print(a,n);           //输出排序后的数组元素
    return 0;
}


void print(int a[],int n){
	for(int i=0 ; i<n ; ++i){
		if(i==0) printf("%d", a[i]);
		else printf(" %d", a[i]);
	}
	printf("\n");
	return;
}

void sort(int a[], int n){
	
	for(int j=1 ; ; j++){
		
		int cnt=0, temp;
		
		for(int i=1 ; i<n ; i++ ){
		
			if( a[i] > a[i-1] ){
				temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
				cnt=1;
			}	
		}
		
		if(cnt==0){
			break;
		}
	}
}

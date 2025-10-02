//C7014

#include<stdio.h>

void print(int [][10],int,int);
void convert(int [][10],int[][10],int,int);

int main()
{
    int a[10][10]={0},b[10][10]={0},n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    print(a,n,m);         //���ת��ǰ�ľ���
    convert(a,b,n,m);     //����װ��
    print(b,m,n);         //���ת�ú�ľ���
    return 0;
} 


void print(int a[][10],int n,int m){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			if(j==0) printf("%d", a[i][j]);
			else 	 printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}

void convert(int a[][10],int b[][10],int n,int m){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			b[j][i] = a[i][j];
		}
	}
}

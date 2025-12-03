//C6046

#include<stdio.h>

int swt(int x);

int main()
{
	int n, k, flag=0;
	
	scanf("%d %d", &n, &k);
	
	int A[n+1];
	
	for(int i=1 ; i<=k ; i++){
		for(int j=1 ; i*j<=n ; j++){
			if(i==1){
				A[i*j] = 1;
			}else{
				A[i*j] = swt(A[i*j]);
			}
		}	
	}
	
	for(int i=1 ; i<=n ; i++){
		if(A[i]==1){
			if(flag==0){
				printf("%d", i);
				flag = 1;
			}else{
				printf(" %d", i);
			}
		}
	}
	
	return 0;
}

int swt(int x)
{
	if(x==0){
		return 1;
	}
	return 0;	
}


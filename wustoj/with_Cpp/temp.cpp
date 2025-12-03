#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int cnt=0;
	int a[n][n];
	
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			a[i][j] = ++cnt;
		}
	}
	
	for(int j=0 ; j<n ; ++j){
		for(int i=n-1 ; i>=0 ; --i){
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 

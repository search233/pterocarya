//7_4

#include<stdio.h>

int main(){
	int n;	scanf("%d", &n);
	
	if(n%2019==0 && n%70!=0){
		printf("right");
	}else{
		printf("wrong");
	}
	
	return 0;
}

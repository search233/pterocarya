//C2001

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int num;	scanf("%d", &num);
	printf("%d=", num);
	
	int n, cnt=10;
	for(int i=0 ; i<4 ; i++){
		n = num % 10;
		num /= 10;
		if(i==0){
			printf("%d", n);
		}else{
			printf("+%d*%d", n, cnt);
			cnt *= 10;
		}
	}
	
	return 0;
}

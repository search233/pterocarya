//7_6

#include<stdio.h>
#include<stdbool.h>

bool prime(int n);

int score(int n);

int main()
{
	int m, n, temp, flag=0;
	int sum_1=0, sum_2=0;
	char ch;
	
	scanf("%d %d", &n, &m);
	
	for(int i=0 ; i<n ; i++){
		scanf("%d", &temp);
		sum_1 += score(temp);
	}
		
	scanf(" %c", &ch);
	if(ch=='N'){
		flag = 1;
	}	 
	
	
	for(int i=0 ; i<m ; i++){
		scanf("%d", &temp);
		sum_2 += score(temp);
	}
	
	if(flag){
		temp = sum_1;
		sum_1 = sum_2;
		sum_2 = temp;
	}
	
	if(sum_1>sum_2){
		printf("heiheihei!");
	}else{
		printf("yingyingying!");
	}
	
	return 0;
}

bool prime(int n){
	bool ret=true;
	
	for(int i=2 ; i<n/i ; i++){
		if(n%i==0){
			ret = false;
			break;
		}
	}
	
	return ret;
}

int score(int n){
	int tmp=0;
	if(prime(n))	tmp += n*n;
	if(n%2==0)		tmp += n*2;
	if(n%3==0)		tmp += n*3;
	return tmp;
}

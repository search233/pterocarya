//1002

#include<stdio.h>

void print(int n);

int main()
{
	char arr[1000] = {0,};	gets(arr);
	int num[102]={0,};
	int sum=0, cnt=0;
	int flag = 0;
	
	for(int i=0 ; arr[i]!=0 ; i++){
		sum += arr[i] - 48;
	}
	 
	while(sum){
		num[cnt++] = sum % 10;
		sum /= 10;
	}
	
	cnt--;
	for( ; cnt>=0 ; cnt--){
		if(flag==0){
			print(num[cnt]);
			flag = 1;
		}else{
			printf(" ");
			print(num[cnt]);
		}	
	}
	
	return 0; 
} 

void print(int num){
	switch(num){
		case 0:	printf("ling");	break;
		case 1:	printf("yi");	break;
		case 2:	printf("er");	break;
		case 3:	printf("san");	break;
		case 4:	printf("si");	break;
		case 5:	printf("wu");	break;
		case 6:	printf("liu");	break;
		case 7:	printf("qi");	break;
		case 8:	printf("ba");	break;
		case 9:	printf("jiu");	break;		
	}
}

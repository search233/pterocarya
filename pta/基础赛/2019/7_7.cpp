//7_7

#include<stdio.h>
#include<stdbool.h>

bool judge(int a);

int main()
{
	int n;	scanf("%d", &n);
	int cnt_cost=0;
	int cnt_num=0; 
	
	for(int i=0 ; i<n ; ++i){
		int a;	scanf("%d", &a);
		if(judge(a)){
			cnt_cost += a;
			++cnt_num;
		}
	}	
	
	printf("%d\n%d", cnt_cost, cnt_num);
	
	return 0;
} 

bool judge(int a){
	bool ret = true;
	
	while(a){
		if(a%10==4){
			ret = false;
			break;
		}
		a /= 10;
	}
	
	return ret; 
}

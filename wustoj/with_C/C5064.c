//C5064

#include<stdio.h>

int judge(int x)
{
	if( (x%4==0 && x%100!=0) || x%400==0 ){
		return 1;
	}
	
	return 0;
}



int main()
{
	int Y1, Y2, M1, M2, D1, D2, day=0;
	
	int N[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	scanf("%d-%d-%d %d-%d-%d", &Y1, &M1, &D1, &Y2, &M2, &D2);
	
		for(int i=Y1 ; i<=Y2 ; i++ ){
			int T1=1, T2=12;
			
			if( judge(i) ){
				N[2] = 29;
			}else{
				N[2] = 28;
			}
			
			if(i==Y1){
				T1=M1;
				day -= D1;
			}
			
			if(i==Y2){
				T2 = M2 - 1;
				day += D2;
			}
			
			for(int j=T1 ; j<=T2 ; j++ ){
				day += N[j];
			}
		}
	
	printf("%d", day);
	
	return 0;
} 

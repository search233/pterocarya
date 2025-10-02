//C2011_A

#include<stdio.h>

int main()
{
	int T1, T2, P, temp;
	
	scanf("%d %d", &T1, &P);
	
	temp = (T1 / 100 * 60) + (T1 % 100) + P;
	
	T2 = (temp / 60 * 100) + (temp % 60);
	
	if(T2 < 100){
		if(T2 <10){
			printf("00%d", T2);
		}else{
			printf("0%d", T2);}
	}else{
		printf("%d",T2);}
	
	return 0;
}

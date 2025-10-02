//C5069

#include<stdio.h>

int judge(int x);


int main()
{
	int Y, M, D, day=10001;
	
	int N[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	int i, j, k;
	
	scanf("%d %d %d", &Y, &M, &D);
	
	int T_j=1, T_k=1;
	
	for( i=Y ; day>0 ; i++ ){
		
		if( judge(i) ){
			N[2] = 29;
		}else{
			N[2] = 28;
		}
		
		if( Y==i ){
			T_k = D;
			T_j = M;
		}
	
		for( j=T_j ; j<=12 && day>0 ; j++){
			
		
			for( k=T_k ; k<=N[j] ; k++ ){
				day--;
				//printf("%d-%d-%d %d\n", i, j, k, day);
				if( day==0 ){
					goto out;
				}
			}
			T_k = 1;
		}
		T_j = 1;
	}
	out:	
		
	printf("%d-%d-%d", i, j, k);
	
	return 0;
}

int judge(int x)
{
	if( (x%4==0 && x%100!=0 ) || x%400==0 ){
		return 1;
	}
	
	return 0;
}

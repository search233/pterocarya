//C5054

#include<stdio.h>

int main()
{
	int N, a=0, b=0, c=0;
	
	scanf("%d", &N);
	
	int score[N];
	
	for(int i=1 ; i<=N ; i++ ){
		
		scanf("%d", &score[i-1]);
		
		if( score[i-1]>=85 ){
			a++;
		}else if(score[i-1]<85 && score[i-1]>=60 ){
			b++; 
		}else{
			c++;
		}
	}
	
	printf("%d %d %d", a, b, c);
	
	return 0;
}

//C4006

#include<stdio.h>

int main()
{
	int score;
	
	scanf("%d", &score);
	
	if(score > 85){
		printf("very good");
	}else if(score <= 85 && score >= 60){
		printf("good");
	}else{
		printf("no good");
	}
	
	return 0;
}

//C6066

#include<stdio.h>

int main()
{
	int ball[7]; 
	int score=0, tag;
		
	for(int i=0 ; i<7 ; i++){
		scanf("%d", &ball[i]);
		if(ball[i]){
			tag = i;
		}
	}
	
	if(!tag){
		tag = -1;
	}
	
	int red = ball[0];
	
	while(red){
		red--;
		score += 2+tag;
	}
	
	for(int i=1 ; i<7 ; i++){
		if(ball[i]){
			score += (i+1) * ball[i];
		}
	}
	
	printf("%d", score);
	
	return 0;
} 

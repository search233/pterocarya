//C6015

#include<stdio.h>

int main()
{
	int n, score[101], max, min, sum=0;
	
	scanf("%d", &n);
	
	for(int i=0 ; i<n ; i++ ){
		
		int temp=0;
		scanf("%d", &temp);
		
		score[i] = temp;
		sum += temp;
		if(i==0){
			max = temp;
			min = temp;
		}else{
			if(temp>max){
				max = temp;
			}else if(temp<min){
				min = temp;
			}
		}
	}
	
	double avg=0;
	avg = sum / (double)n;
	int cnt=0;
	
	for(int i=0 ; i<n ; i++ ){
		if(score[i]>avg){
			cnt++;
		}
	}
	
	printf("%d %d %d", max, min, cnt);
	
	return 0;
} 

//C6057

#include<stdio.h>
#include<math.h>


int main()
{
	int N;
	int num[10000] ={0};
	double sum=0, S=0;
	
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; i++){
		scanf("%d", &num[i]);
		sum += num[i];
	}
	
	double avg;
	avg = sum / N;
	
	for(int i=0 ; i<N ; i++){
		S += (num[i]-avg)*(num[i]-avg);
	}	
	
	S = sqrt(S/N);
	
	printf("%.5f", S);
	
	return 0;
}

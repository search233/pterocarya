//C6039

#include<stdio.h>

int main()
{
	int N, ans1[101], ans2[101];
	double cnt=0, rate;
	
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; i++){
		scanf("%d", &ans1[i]);
	} 
	
	for(int i=0 ; i<N ; i++){
		scanf("%d", &ans2[i]);
	} 
	
	for(int i=0 ; i<N ; i++){
		if(ans1[i]==ans2[i]){
			cnt++;
		}
	} 

	rate = cnt / N;
	
	printf("%.2f%%", rate*100);
	
	return 0;
}

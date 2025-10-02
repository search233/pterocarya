//C6033

#include<stdio.h>

int main()
{
	int F[1001] = { 0,};
	int N;
	//int find[], cnt=0;
	
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; i++){
		int K, tag;
		scanf("%d", &K);
		
		for(int j=0 ; j<K ; j++){
			scanf("%d", &tag);
			F[tag]++;
		}
	} 
	
	int cnt=1, tag_out;
	for(int i=0 ; i<1001 ; i++){
		if(F[i]>=cnt){
			cnt = F[i];
			tag_out = i;
		}
	}
	
	printf("%d %d", tag_out, cnt);
	
	return 0;
}

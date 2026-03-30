//C5034

#include<stdio.h>

int main()
{
	int N, S=1;
	
	scanf("%d", &N);
	
	for(int i=N ; i>1 ; i-- ){
		S = (S + 1) * 2;
	} 
	
	printf("%d", S); 
	
	return 0;
}

//C6031

#include<stdio.h>
#include<string.h>

int main()
{
	int n[10] = { 0,};
	char N[1001];
	int len;
	
	gets(N);
	len = strlen(N);
	
	for(int i=0 ; i<len ; i++){
		n[N[i]-48]++;
	}
	
	for(int i=0 ; i<10 ; i++){
		if(n[i]){
			printf("%d:%d\n", i, n[i]);
		}
	}
	
	return 0;
}

//C6070

#include<stdio.h>
#include<string.h>


int main()
{
	char str1[1001];	gets(str1);
	char str2[1001];	gets(str2);

	int len1 = strlen(str1), len2 = strlen(str2);		
	int max = (len1>len2) ? len1 : len2;
	int A[1001] = {0}, B[1001] = {0};
	
	for(int i=len1-1, t=0 ; i>=0 ; i--, t++){
		A[i] = (int)str1[t]-48;
	}
	
	for(int i=len2-1, t=0 ; i>=0 ; i--, t++){
		B[i] = (int)str2[t]-48;
	}
	
	for(int i=0 ; i<max ; i++){
		A[i] += B[i];
		A[i+1] += A[i]/10;
		A[i] %= 10; 
	}	
	
	int tag;
	for( tag=max ; A[tag]==0 ; tag--);
	
	for(int i=tag ; i>=0 ; i--){
		printf("%d", A[i]);
	}
	
	return 0;
}

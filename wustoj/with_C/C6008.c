//C6008

#include<stdio.h>

int main()
{
	char ch='a';
	
	int cnt[10] = { 0 };

	while( ch!='!' ){
		
		ch = getchar();
		
		if( ch>='0' && ch<='9' ){
			int j = ch-'0';
			cnt[j]++;
		} 
	}
	
	for(int i=0 ; i<10 ; i++){
		printf("The character %c appears %d times\n", i+48, cnt[i]);
	}
	
	return 0;
}

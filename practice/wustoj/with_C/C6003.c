//C6003

#include<stdio.h>

int main()
{
	int N[26] = {0,}, cnt=0;
	
	char ch = 'a'; 
	
	for(int i=0 ; ch!='\n' ; i++ ){
		
		ch = getchar();
		
		for(int j=0 ; j<26 ; j++ ){
			
			if( ch==j+65 ){
				N[j]++;
				break;
			}
		}
	}
	
	for(int i=0 ; i<26 ; i++ ){
		printf("%c(%d)", i+65, N[i]);
		cnt++;
		
		if(cnt==5){
			printf("\n");
			cnt=0;
		}
	}
	
	return 0;
}

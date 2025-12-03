//C6021

#include<stdio.h>

int main()
{
	char asc[101] = {' '}, ch;
	int i=0; 
	//getchar();
	
	for( i=0 ; (ch = getchar())!='\n' && ch!=EOF ; i++ ){
		
		asc[i] = ch;
		if(asc[i]>='A' && asc[i]<='Z'){
			asc[i] += 32;
		}
	}
	
	for(int i=0 ; asc[i]!=-1 && asc[i]!='\0' ; i++){
		printf("%c", asc[i]);
	}
	
	return 0;
	
}

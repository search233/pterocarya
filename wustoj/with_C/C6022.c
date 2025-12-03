//C6022

#include<stdio.h>
#include<string.h>

int main()
{
	char str[101];
	char ch;
	int len, j=0;
	
	gets(str);
	scanf("%c", &ch);
	
	len = strlen(str);
	
	for(int i=0 ; i<len ; i++ ){
		if(str[i]!=ch){
			str[j++] = str[i];	
		}
	}
	
	str[j] = '\0';
	puts(str);
	
	return 0;
}

//C6042

#include<stdio.h>
#include<string.h>

int main()
{
	char str[90], temp;
	int len;
	
	gets(str);
	len = strlen(str);
	 
	
	for(int i=0 ; i<len; i++){
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
		if(i+1==len-i-1 || i==len-i-1){
			break;
		}
	}
	
	puts(str);
	
	return 0;
}

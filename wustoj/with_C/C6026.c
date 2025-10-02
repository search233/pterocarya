//C6026

#include <stdio.h>
#include<string.h>

int main()
{
	char str1[101],str2[101];
    int i,j;
    int len;
  
    gets(str1);
	len = strlen(str1);
	
	for( i=len-1, j=0 ; i>=0 ; i--, j++){
		str2[j] = str1[i];
	}
	str2[j] = '\0';
  
    puts(str2);
  
    return 0;
}

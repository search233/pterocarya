//C6028

#include<stdio.h>
#include<string.h>


int main()
{
	char str1[101], str2[101];
	int len1, len2;
	int cmp=0;
	
	gets(str1);
	gets(str2);
	
	len1 = strlen(str1);
	len2 = strlen(str2);
	
	for(int i=0 ; i<=len1 && i<=len2 ; i++){
	
		if(str1[i]!=str2[i]){
			cmp = (int)str1[i] - (int)str2[i];
			break;
		}
	}
	
	printf("%d", cmp);
	
	return 0;
}

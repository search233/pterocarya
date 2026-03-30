//C6010

#include<stdio.h>
#include<string.h>

int main()
{
	char str1[80], str2[80];
	int n;
	
	scanf("%d", &n);
	getchar();
	
	for(int i=1 ; i<=n ; i++ ){
		gets( str2 );
		
		if(i==1){
			strcpy(str1, str2);
			continue;
		}
		
		if( strcmp(str1, str2)<=0 ){
			strcpy(str1, str2);
		}
	}
	
	puts(str1);
	
	return 0;
}

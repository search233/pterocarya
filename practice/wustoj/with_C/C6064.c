//C6064

#include<stdio.h>
#include<string.h>

int main()
{
	char str[90];
	int len, mid, flag=1;
	
	gets(str);
	len = strlen(str);
	
	if(len%2){
		mid = (len-1) / 2;
		for(int i=0 ; mid-i>=0 ; i++){
			if(str[i+mid]!=str[mid-i]){
				flag = 0;
				break;
			}
		}
	}else{
		mid = (len-2) / 2;
		for(int i=0 ; mid-i>=0 ; i++){
			if(str[i+1+mid]!=str[mid-i]){
				flag = 0;
				break;
			}
		}
	}
	
	puts(str);

	
	if(flag){
		printf("Yes");
	}else{
		printf("No");
	}
	
	return 0;
}

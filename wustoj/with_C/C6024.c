//C6024

#include<stdio.h>
#include<string.h>


int main()
{
	char str[1001];
	
	gets(str);
	
	int len = strlen(str);
	int flag=1;
		
		while(flag){
			flag = 0;
			
			for(int i=2 ; i<len ; i+=2){
				char temp;
				
				if(str[i]<str[i-2]){
					temp = str[i-2];
					str[i-2] = str[i];
					str[i] = temp;
					
					flag=1;
				}
			}
		}
	


	puts(str);
	
	return 0;
}


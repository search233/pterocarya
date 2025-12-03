//C6011

#include<stdio.h>
#include<string.h>


int int_pow(int x)
{
	int ret = 1;
	
	for(int i=1 ; i<=x ; i++ ){
		ret *= 16;
	}
	
	return ret;
}

int main()
{
	char str[80], ox[80];
	int cnt = 0;
	int num = 0;
	
	gets(str);
	
	for(int i=0 ; str[i]!='#' ; i++ ){
		
		if( (str[i]>='0' && str[i]<='9') 
		||(str[i]>='A' && str[i]<='F')
		||(str[i]>='a' && str[i]<='f') ){
			
			ox[cnt] = str[i];
			cnt++;	
		}
	}
	
	
	ox[cnt++] = '\0';
	
	int temp = strlen(ox);	
	
	for(int i=0 ; ox[i]!='\0' ; i++ ){
		
		int p = temp -1 -i;
		
		if( ox[i]>='0' && ox[i]<='9' ){
			num += int_pow(p) * ((int)ox[i] - 48);
			
		}else if( ox[i]>='A' && ox[i]<='F' ){
				num += int_pow(p) * ((int)ox[i] - 55);
					
		}else if( ox[i]>='a' && ox[i]<='f' ){
				num += int_pow(p) * ((int)ox[i] - 87);
		}		
	}
	
	printf("String:%s\nnumber=%d", ox, num);
	
	return 0;
}

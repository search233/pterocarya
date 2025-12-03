//C6060

#include<stdio.h>
#include<string.h>

int main()
{
	int cnt=0, len;
	char str[1001];
	
	gets(str);
	len = strlen(str);
	
	for(int i=0 ; i<len ; i++){
		if(str[i]=='6'){
			cnt++;
		}else{
			if(cnt<=3 && cnt>0){
				for(int j=cnt ; j>0 ; j--){
					printf("6");
				}
			}else if(cnt>3 && cnt<=9){
				printf("9");
			}else if(cnt>9){
				printf("27");
			}
			printf("%c", str[i]);
			cnt=0;
		}
	}
	
	if(cnt<=3 && cnt>0){
		for(int j=cnt ; j>0 ; j--){
			printf("6");
		}
	}else if(cnt>3 && cnt<=9){
		printf("9");
	}else if(cnt>9){
		printf("27");
	}
		
	return 0;
}

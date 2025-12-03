//C6063

#include<stdio.h>
#include<string.h>

int main()
{
	int cnt_ch=0, cnt_num=0, cnt_point=0;
	int len;
	char str[90];
	
	gets(str);
	len = strlen(str);
	
	if(len<6){
		printf("Your password is tai duan le.");
		return 0;
	}else{
		for(int i=0 ; i<len ; i++){
			
			if(str[i]>='0' && str[i]<='9'){
				cnt_num++;
			}else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
				cnt_ch++;
			}else if(str[i]=='.'){
				cnt_point++;
			}else{
				printf("Your password is tai luan le.");
				return 0;
			}
		}
		
		if(cnt_ch==0 && cnt_num!=0){
			printf("Your password needs zi mu.");
			return 0;
		}
		if(cnt_num==0 && cnt_ch!=0){
			printf("Your password needs shu zi.");
			return 0;
		}
		if(cnt_num==0 && cnt_ch==0){
			printf("Your password zhi you dian.");
			return 0;
		}
	}
	
	printf("Your password is wan mei.");
	return 0;
}

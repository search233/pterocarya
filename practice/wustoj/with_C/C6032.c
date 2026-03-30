//C6032

#include<stdio.h>
#include<string.h>

int main()
{
	char str[1001];
	int len;
	int cnt=0;
	
	gets(str);
	len = strlen(str);
	
	for(int i=0 ; i<len ; i++){
		
		int k=0;
		int count = 1;
		
		do{
			count++;
		}while(str[i]==str[i+count-1]);
		
		count--;
		
		if(count%2==1){
			i += (count-1)/2;
			while(i-k>=0){
				if(str[i+k]==str[i-k]){
					k++;
				}else{
					break;
				}
			}
			k = k*2-1;
			
		}else{
			i += (count-2)/2;
			while(i-k>=0){
				if(str[i+k+1]==str[i-k]){
					k++;
				}else{
					break;
				}
			}
			k *= 2;			
		}	
		
		if(k>cnt){
			cnt = k;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}

//C6055

#include<stdio.h>
#include<string.h>

int main()
{
	char N[55];
	int len;
	double rate=1, cnt=0;
	
	gets(N);
	len = strlen(N);
	
	
	for(int i=0 ; i<len ; i++){
		if(N[i]=='2'){
			cnt++;
		}
	}
	
	
	if(N[len-1]%2==0){
		rate *= 2;
	}	
	if(N[0]=='-'){
		rate *= 1.5;
		--len;
	}

	
	rate *= cnt / len;
	rate *= 100;
	
	printf("%.2f%%", rate);
	
	return 0;
}

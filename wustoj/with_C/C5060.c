//C5060

#include<stdio.h>

int main()
{
	int H, M, times;
	
	scanf("%d:%d", &H, &M);
	
	if( H<12 || (H==12 && M==0) ){
		printf("Only %02d:%02d.  Too early to Dang.", H, M);
		
	}
	else{
		
		if( M==0 ){
			times = H - 12;
		}else{
			times = H - 11;
		}
		
		for(int i=1 ; i<=times ; i++ ){
			printf("Dang");
		}
	}
	
	return 0;
}

//C5048

#include<stdio.h>

int main()
{
	int T, rab=0, tur=0, left;
	
	scanf("%d", &T);
	
	for(int i=1 ; i<=T ; i++ ){
		
		tur += 3;
		rab += 9;
		
		left = T - i;
		
		if( i%10 == 0 ){
			
			if( rab>tur ){
				
				if( left>=30 ){
					i += 30;
					tur += 90;
									
				}else{
					tur += left * 3;
					break;
				}
			}
		}
	}
	
	if( tur>rab ){
		printf("@_@ %d", tur);
	}
	
	if( tur==rab ){
		printf("-_- %d", tur);
	}
	
	if( tur<rab ){
		printf("^_^ %d", rab);
	}

	return 0;
}

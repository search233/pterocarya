//C5006

#include<stdio.h>
#include<math.h>

int main()
{
	int n, line, i, j;
	
	scanf("%d", &n);
	
	line = n * 2 - 1;
	
	for( i = n-1 ; i>-n ; i-- ){
		//printf("#\n");Ñ­»·Îå´Î 
		
		for( j=1 ; j<=abs(i) ; j++ ) {
			printf(" ");
		}
		
		for( j=1 ; j<=line - abs(i) * 2 ; j++ ){
			printf("*"); 
		}
		
		printf("\n");
	}
	
	return 0;
}

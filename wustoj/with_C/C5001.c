//C5001

#include<stdio.h>

 int main()
 {
 	int n, i, x, num;
 	
 	scanf("%d\n%d", &n, &num);
 	
 	for( i=1 ; i<n ; i++ ){
 		
	 	scanf("%d", &x);
	 	
	 	if( x>num ){
		 	num = x;
		}
	}
	 
	printf("%d", num);
	
	return 0;
 }

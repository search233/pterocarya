//C5011

#include<stdio.h>

int main(){
	int n, i;
	
	double H=100, Hn=100;
	 
	 
	scanf("%d", &n);
	 
	 
	for( i=1 ; i<=n ; i++ ){
		
		Hn /= 2;
		 
		H += Hn * 2;
		
	} 
	
	if( n>1 ){
		printf("%f %f", H - Hn*2, Hn);
	}else{
		printf("%f %f", H=100, Hn);
	}	
	
	return 0;
}

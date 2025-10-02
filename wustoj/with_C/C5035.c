//C5035

#include<stdio.h>
#include<math.h>


int int_pow(int base, int exp) 
{
    int result = 1;
    
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    
    return result;
}


int f ( int x , int n){

	int each, S=0, temp;
	
	temp = x;
	
	
	do{
		
		each = temp % 10;
		S += int_pow(each,n);
		temp /= 10;
		
	}while( temp!=0 );
	
	return ( S==x );
}



int main(){
	int N;
	
	scanf("%d", &N);
	
	for(int i=int_pow(10,N-1) ; i<=int_pow(10,N)-1 ; i++ ){
		
		if( f(i,N) ){
			printf("%d\n", i);
		}
	}
	
	return 0;
	
}



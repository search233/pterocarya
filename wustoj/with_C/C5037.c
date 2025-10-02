//C5037

#include<stdio.h>

int change_to_max( int x )
{
	int a, b, c, out_Max, temp=0;
	
	temp = x;
	
	a = temp / 100;
	c = temp % 10;
	b = (temp/10) % 10;
	
	if( b>a && a>c ){
		temp = b;
		b = a;
		a = temp;
	}
	
	if( b>c && c>a ){
		temp = b;
		b = c;
		c = a;
		a = temp;
	}
	
	if( c>b && b>a ){
		temp = c;
		c = a;
		a = temp;
	}
	
	if( c>a && a>b ){
		temp = c;
		c = b;
		b = a;
		a = temp;
	}
	
	if( a>c && c>b ){
		temp = c;
		c = b;
		b = temp;
	}
	
	out_Max = a*100 + b*10 + c;

	return out_Max;
}

int change_to_min( int x )
{
	int a, b, c, out_Min, temp=0;
	
	temp = x;
	
	a = temp / 100;
	c = temp % 10;
	b = (temp/10) % 10;
	
	if( b>a && a>c ){
		temp = b;
		b = a;
		a = temp;
	}
	
	if( b>c && c>a ){
		temp = b;
		b = c;
		c = a;
		a = temp;
	}
	
	if( c>b && b>a ){
		temp = c;
		c = a;
		a = temp;
	}
	
	if( c>a && a>b ){
		temp = c;
		c = b;
		b = a;
		a = temp;
	}
	
	if( a>c && c>b ){
		temp = c;
		c = b;
		b = temp;
	}
	
	out_Min = c*100 + b*10 + a;

	return out_Min;
}


int main()
{
	int N, temp;
	
	scanf("%d", &N);
	
	for(int i=1 ; ; i++ ){
		
		temp = change_to_max(N) - change_to_min(N);
		
		printf("%d: %d - %d = %d\n", i, change_to_max(N), change_to_min(N), temp);
		
		if( temp>100 ){
			N = temp;
		}else if( temp<100 && temp>10){
			N = temp*10;
		}else{
			N = temp*100;
		}
		
		if( N==495 ){
			break;
		}
	}
	
	return 0;
}

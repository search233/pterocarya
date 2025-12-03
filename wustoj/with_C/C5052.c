//C5052

#include<stdio.h>

int sum( int x );

int judge( int x );


int main()
{
	int a, b, flag=0, temp;
	
	scanf("%d %d", &a, &b);
	
	for(int i=a ; i<=b ; i++ ){
		
		temp = judge(i);
		
		if( temp!=0 ){
			printf("%d(%d)\n", i, temp);
			flag = 1;
		}	
	}
	
	
	if( flag==0 ){
		printf("None");
	}
	
	return 0;
}



int sum( int x )
{
	int S=0;
	
	while( x ){
		S += x % 10;
		x /= 10;
	}	
	
	return S;
}


int judge( int x )
{
	
	int temp, y, count = 0;
	
		temp = sum(x);
	
		for (int i = 2; i < 10; i++)
		{
			y = sum(x * i); 
			 
			if (y != temp){
				break;
			}
			
			count++;
		}
	
		if (count == 8){
			return temp;			
		}else{
			return 0;
		} 		
}

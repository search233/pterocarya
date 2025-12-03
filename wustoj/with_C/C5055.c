//C5055

#include<stdio.h>

char tran( char c )
{
	if( c>=97 && c<122){
		c -= 31; 
	}else if( c==122 ){
		c = 65;
	}else if( c>=65 && c<90 ){
		c += 33;
	}else if( c==90 ){
		c = 97;
	}
	
	return c;
}

int main()
{
	char ch;
	
	for (int i=1 ; ; i++ ){
		
		ch = getchar();
		
		ch = tran( ch );
		
		if( ch == '\n' ){
			break;
		}
		
		printf("%c", ch);
	}
	
	return 0;
}

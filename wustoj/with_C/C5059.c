//C5039

#include<stdio.h>

int prime(int x);

int main()
{
	int m, cnt=1;
	
	scanf("%d", &m);
	
	for(int i=m-1 ; ; i-- ){
		
		if( prime(i) ){
			
			if( cnt==1 ){
				printf("%d", i);
				cnt++; 
				
			}else if( cnt>0 && cnt<10 ){
				printf(" %d", i);
				cnt++;
				
			}else if( cnt==10 ){
				printf(" %d", i);
				break;
			}
		}
	}
	
	return 0;
}



int prime( int x )
{
	int flag=1;
	
	if( x%2==0 && x!=2 ){
		flag=0;
		
	}else if( x==2 ){
		goto out;
	}else{
		
		for(int i=3 ; i<x ; i+=2 ){
			
			if( x%i==0 ){
				flag=0;
				break;
			}
		}	
	}
	
	out:
	return flag;
}

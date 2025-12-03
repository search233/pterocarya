//C5047

#include<stdio.h>


int main()
{
	int X, cnt=0;
	
	scanf("%d", &X);
		
	printf("%d=", X);
	
	if( X%2==0 ){					//若为偶数则先将2除净 
		
		while( X%2==0 ){
					
			if( X==2 ){
				
				if(cnt==0){ 
					printf("%d", 2);
				}else{
					printf("*%d", 2);
				}							//X为2的N次方时输出最后一个2并结束程序 
				goto out;
			}
			
			X /= 2;
			
			if( cnt==0 ){
				printf("%d", 2);			//不断除2，并根据所在位置输出*号 
				cnt=1;
						
			}else{
				printf("*%d", 2);
			}
		}									//2被除尽后跳出循环 	
	} 

	for(int i=3 ; ; i+=2 ){					//处理剩下的奇数
	
		if( X==i ){							
			
			if( cnt==1 ){					 //除到最后一个数时输出并跳出
				printf("*%d", i);
				break;
				
			}else {							 //X为素数时跳出 
				printf("%d", X);
				break;
			} 
		}
				
		if( X%i==0 ){
					
			do{
						
				if( cnt==0 ){				//X为奇数除掉第一个奇数 
					printf("%d", i);
					cnt=1;
						
				}else{
					printf("*%d", i);
				}
					
				X /= i;
				
				if( X==1 ){
					goto out;
				}
			}while( X%i==0 );				
		}
	}			
	out:
		
	return 0;

}

//C5047

#include<stdio.h>


int main()
{
	int X, cnt=0;
	
	scanf("%d", &X);
		
	printf("%d=", X);
	
	if( X%2==0 ){					//��Ϊż�����Ƚ�2���� 
		
		while( X%2==0 ){
					
			if( X==2 ){
				
				if(cnt==0){ 
					printf("%d", 2);
				}else{
					printf("*%d", 2);
				}							//XΪ2��N�η�ʱ������һ��2���������� 
				goto out;
			}
			
			X /= 2;
			
			if( cnt==0 ){
				printf("%d", 2);			//���ϳ�2������������λ�����*�� 
				cnt=1;
						
			}else{
				printf("*%d", 2);
			}
		}									//2������������ѭ�� 	
	} 

	for(int i=3 ; ; i+=2 ){					//����ʣ�µ�����
	
		if( X==i ){							
			
			if( cnt==1 ){					 //�������һ����ʱ���������
				printf("*%d", i);
				break;
				
			}else {							 //XΪ����ʱ���� 
				printf("%d", X);
				break;
			} 
		}
				
		if( X%i==0 ){
					
			do{
						
				if( cnt==0 ){				//XΪ����������һ������ 
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

//C5019

#include<stdio.h>
#include<math.h>


int prime( long x )
{
	for ( long i=2 ; i<x ; i++ )
	{
		if ( x%i==0 ) {
			return 0;
		}
	}
	
	return 1;
}



int main()
{
	long N, A, cnt =0, count=1, start;
	//��A��ʼ��cnt���� 
	//����count��¼��С�������ӣ�
	//count_max������ 
	
	scanf("%ld", &N);//����N 
	
	if(prime(!N))
	{
		for ( long i=2 ; i<(long)sqrt(N) ; i++ ){
			
			if( N%i==0 ){		//�������Ӻ���A��������¼���� 
			
				for( long j=i ; j<N ; j++){	
					A = i++;				
					cnt++;
					
					if( N%A==0 ){
						
						count = cnt;
					}else{
						
						count = cnt-1;
						start = A - count; //��start��count��λ����С���������� 
						break;
					} 
				}
			}
			
		}
		
		printf("%ld", cnt);
	}else{
		printf("1\n%ld", N); 
	}
	
	return 0;
}

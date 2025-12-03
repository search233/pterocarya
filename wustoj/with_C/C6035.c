//C6035

#include<stdio.h>
#include<string.h>

int main()
{
	char A[10001], B[10001];
	
	gets(A);
	gets(B);
	
	int len_a = strlen(A);
	int len_b = strlen(B);
	int i=0, j=0;
	
	for( i=0 ; i<len_a ; i++)
	{
		for( j=0 ; j<len_b ; j++)
		{
			if(A[i]==B[j]){
				
				for(int k=i ; k<len_a ; k++){
					A[k] = A[k+1]; 
				} 
				len_a--;
				i--;
			}
		}
	}
	
	puts(A);
	
	return 0;
}

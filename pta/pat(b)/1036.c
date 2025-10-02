//1036

#include<stdio.h>
#include<math.h>

int main()
{
	int n;	char ch;
	scanf("%d %c", &n, &ch);
	
	int row = (int)round(n*0.5);
	for(int i=1 ; i<=row ; i++){
		
		if(i==1 || i==row){
			
			for(int i=0 ; i<n ; i++){
				printf("%c", ch);
			}
			
			if(i==1)	printf("\n");
		}else{
			printf("%c", ch);
			for(int j=0 ; j<n-2 ; j++){
				printf(" ");
			}
			printf("%c\n", ch);
		}
	}	
} 

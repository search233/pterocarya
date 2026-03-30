//C6038

#include<stdio.h>

int main()
{
	int W[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2,};
	char id[19];
	char M[11] = {'1', '0', 'x', '9', '8', '7', '6', '5', '4', '3', '2'};
	
	gets(id);
	
	int sum=0, z;
	
	for(int i=0 ; i<17 ; i++){
		if(id[i]>='0' && id[i]<='9'){
			sum += ((int)id[i] - 48) * W[i];
		}else{
			printf("Incorrect");
			return 0;
		}
	}
	
	z = sum % 11;
	
	if(M[z]==id[17]){
		printf("No problem");
	}else{
		printf("Incorrect");
	}
	
	return 0;
}

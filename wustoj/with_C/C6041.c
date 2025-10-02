//C6041

#include<stdio.h>

int main()
{
	int Na, Nb, cnt=0;
	int A[25] ={0}, B[25] ={0};
	int C[50] ={0};
	
	scanf("%d", &Na);
	
	for(int i=0 ; i<Na ; i++){
		scanf("%d", &A[i]);
	}

	scanf("%d", &Nb);
	
	for(int i=0 ; i<Nb ; i++){
		scanf("%d", &B[i]);
	}
	
	for(int i=0 ; i<Na ; i++){
		for(int j=0 ; j<Nb ; j++){
			if(A[i]==B[j]){
				break;
			}
			if(j==Nb-1){
				C[cnt++] = A[i];
			}
		}	
	}

	for(int i=0 ; i<Nb ; i++){
		for(int j=0 ; j<Na ; j++){
			if(B[i]==A[j]){
				break;
			}
			if(j==Na-1){
				C[cnt++] = B[i];
			}
		}	
	}
	
	for(int i=0 ; i<cnt ; i++){
		if(i==0){
			printf("%d", C[i]);
		}else{
			for(int j=0 ; j<i ; j++){
				
				if(C[j]==C[i]){
					break;
				}else if(j==i-1){
					printf(" %d", C[i]);
				}
			}
		}
	} 

	return 0;	
}

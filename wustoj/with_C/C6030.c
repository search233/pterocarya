//C6030

#include<stdio.h>
#include<math.h>


int prime(int x);

int main()
{
	int n, k;
	int sum=0;
	int P[11], cnt=0;
	
	scanf("%d %d", &n, &k);
	
	for(int i=n ; ; i--){
		
		if(i==1){
			break;
		}
		
		if(prime(i)){
			P[cnt++] = i;
			sum += i;
			if(cnt==k){
				break;
			}
		}
	}
	
	for(int i=0 ; i<cnt ; i++){
		if(i==0){
			printf("%d", P[i]);
		}else{
			printf("+%d", P[i]);
		}
	}
	
	printf("=%d", sum);
	
	return 0;
}


int prime(int x)
{
	if(x!=1){
		for(int i=2 ; i<=(int)sqrt(x) ; i++){
			if(x%i==0){
				return 0;
			}
		}
	}else if(x==1){
		return 0;
	}
	
	return 1;
}

//7_6

#include<stdio.h>

int pow(int a, int b);

int light[100000] = {1};

int main()
{
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	
	int temp;
	for(int i=2 ; i<=n ; i++){
		for(int j=1 ; ; j++){
			temp = pow(i,j)-1;
			if(temp<=m)	light[temp]=1;
			else break;
		}
	}
	
	for(int i=0 ; i<k ; i++){
		scanf("%d", &temp);
		if(light[temp-1])	printf("No\n");
		else			printf("Yes\n");
	}
	
	return 0;
}

int pow(int a, int b){
	int ret=1;
	for(int i=0 ; i<b ; i++)	ret *= a;
	return ret;
}

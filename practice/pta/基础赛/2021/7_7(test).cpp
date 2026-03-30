//7_7(test)

#include<stdio.h>

int list[2][20000] = {{3,9,8}};

int main()
{
	int n; scanf("%d", &n);
	int len=3, tag=1;
		
	for(int i=1 ; i<=n ; ++i){
		for(int j=0 ; j<len ; j++){
			list[tag][j*2] = list[tag^1][j];
			list[tag][2*j+1] = list[tag^1][j+1] - list[tag^1][j];
		}
		len = len *2 -1;
		tag ^= 1;
	}
		
	tag ^= 1;
	int sum=0;
	for(int i=0 ; i<len ; ++i){
	//	printf("%d ", list[tag][i]);
		sum += list[tag][i];
	}
	printf("%d %d\n", sum-20, sum);
	
		
	return 0;
}

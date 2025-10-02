//C6059

#include<stdio.h>

int main()
{
	int n[1000];
	n[1] = 1;
	n[2] = 2;
	n[3] = 3;
	
	int day;
	scanf("%d", &day);
	
	for(int i=4 ; i<=day ; i++){
		n[i] = n[i-1]*2 - n[i-3];
	}
	
	printf("%d", n[day]);
	
	return 0;
}


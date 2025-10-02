//7_4

#include<stdio.h>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	
	m -= 10;
	
	int ret;
	
	if(m>0){
		ret = (m+n-1)/n;
	}else{
		ret = 0;
	}
	

	printf("%d", ret);
	
	return 0;
}

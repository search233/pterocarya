//C2009

#include<stdio.h>

int main()
{
	int x, y, s, h;
	const int k = 50;
	
	scanf("%d %d", &x, &y);
	
	h = x - y;
	
	if(h < 0){
		h = -h;
	}
	
	s = k * h;
	
	printf("%d", s);
	
	return 0;
}

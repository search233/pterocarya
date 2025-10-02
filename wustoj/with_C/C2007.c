//C2007

#include<stdio.h>

int main()
{
	int H;
	
	float W, KG;
	
	scanf("%d", &H);
	
	KG = (H - 100)*0.9;
	
	W = KG * 2;
	
	printf("%.1f", W);
	
	return 0;
}

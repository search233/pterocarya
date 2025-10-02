//C2005

#include<stdio.h>

int main()
{
	const float k = 30.48;
	
	int cm, foot, inch;
	
	scanf("%d", &cm);
	
	foot = cm / k;
	
	inch = (cm / k - foot) * 12;
	
	printf("%d %d\n", foot, inch);
	
	return 0;
}

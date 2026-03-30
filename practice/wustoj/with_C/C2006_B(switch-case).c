//C2006(switch-case)

#include<stdio.h>

int main()
{
	int D;
	
	scanf("%d", &D);
	
	switch (D) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			D += 2;
			break;
		case 6:
			D = 1;
			break;
		default:
			D = 2;
			break;
	}
	
	printf("%d", D);
	
	return 0;
}

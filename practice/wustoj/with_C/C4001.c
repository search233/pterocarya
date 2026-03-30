//C4001

#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c, num, temp;
	
	scanf("%d", &num);
	
	a = num / 100;
	
	c = num % 10;
	
	b = num % 100 / 10;
	
	temp = pow(a,3) + pow(b,3) + pow(c,3);
	
	if(num == temp){
		printf("YES");
	} else {
		printf("NO");
	}
	
	return 0;
}

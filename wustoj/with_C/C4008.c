//C4008

#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c, x, y, z;
	
	scanf("%d %d %d", &x, &y, &z);
	
	c = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
	//计算最大值 
	
	b = (x > y) ? ((x > z) ? ((y > z) ? y : z) : x) : ((y > z) ? ((x > z) ? x : z) : y); 
	//计算中间值
	 
	a = x + y + z - b - c;
	
	if(a + b > c){
		printf("YES");
	}else{
		printf("NO");
	}
	
	return 0;
}

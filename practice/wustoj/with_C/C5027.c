//C5027

#include<stdio.h>
#include<math.h>

int main()
{
	int m, n;
	
	double S=0;
	
	scanf("%d %d", &m, &n);
	
	for (int i=m ; i<=n ; i++ ){
		S += pow(i,2) + 1.0/i;
	}
	
	printf("%f", S);
	
	return 0;
}

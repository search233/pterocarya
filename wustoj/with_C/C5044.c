//C5044

#include<stdio.h>
#include<math.h>

int main()
{
	int N, X, Y, flag=0;
	
	scanf("%d", &N);
	
	for(int i=1 ; i<=(int)sqrt( (double)N ) ; i++ ){
		X = i;
		Y = (int)sqrt(N - X*X );
		
		if( X>Y ){
			break;
		}
		
		if( X*X + Y*Y == N ){
			printf("%d %d\n", X, Y);
			flag = 1;
		}
	}
	
	if( flag==0 ){
		printf("No Solution");
	}
	
	return 0;
}

//C4002

#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b){
		if(c > a){
			printf("a=%d,b=%d,c=%d", b, a, c);
		} else if(c < b){
			printf("a=%d,b=%d,c=%d", c, b, a);
		}else{
			printf("a=%d,b=%d,c=%d", b, c, a);
		}
	} else {
		if(c > b){
					printf("a=%d,b=%d,c=%d", a, b, c);
				} else if(c < a){
					printf("a=%d,b=%d,c=%d", c, a, b);
				}else{
					printf("a=%d,b=%d,c=%d", a, c, b);
				}
	}
	
	return 0;
}

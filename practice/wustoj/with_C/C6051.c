//C6051

#include<stdio.h>

int pow2(int x);

int main()
{
	int x1=0, x2=0, x3=0, x4=0;
	int cnt=4;
	char temp;
	
	for(int i=1 ; i<=4 ; i++){
		for(int j=7 ; j>=0 ; j--){
			
			temp = getchar();
			int x=(int)temp-48; 
			
			switch (cnt) {
				case 4:
					x4 += x * pow2(j);
					break;
				case 3:
					x3 += x * pow2(j);
					break;
				case 2:
					x2 += x * pow2(j);
					break;
				case 1:
					x1 += x * pow2(j);
					break;
			}
		} 
		cnt--;
	}
	
	printf("%d.%d.%d.%d", x4, x3, x2, x1);
	
	return 0;
}

int pow2(int x)
{
	int ret=1; 
	for(int i=1 ; i<=x ; i++){
		ret *= 2;
	}
	return ret;
}

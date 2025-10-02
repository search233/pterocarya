//C5024

#include<stdio.h>

double trans( char c , double H){
	
	double out;
	
	if( c=='F'){
		out = H * 1.09;
		
	}else if( c=='M'){
		out = H / 1.09;
	}
	
	return out;
	
}

int main()
{
	int N;
	double hight;
	char sex;
	 
	
	
	scanf("%d", &N);
	
	for (int i=1 ; i<=N ; i++ ){
		
		getchar();
		
		scanf("%c %lf", &sex, &hight);
		
		printf("%.2f\n", trans(sex, hight));
	}
	
	return 0;
}

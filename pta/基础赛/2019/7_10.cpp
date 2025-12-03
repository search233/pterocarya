//7_10

#include<stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	char ch[1000];
	
	int sum=0, Q_cnt=0, temp=0;
	
	getchar();
	
	for(int i=0 ; i<n ; ++i){
		scanf("%c", &ch[i]);
		getchar();
		if(ch[i]=='E')	ch[i] = ch[i-1];
		if(ch[i]=='S')	n += 2; 
	}
	
	for(int i=0 ; i<n ; ++i){
		
		switch(ch[i]){
			case 'Q':	temp = ++Q_cnt * 65; break;
			case 'W':	
				if(temp>=250){
					temp *= 0.5;
				}else{
					temp *= 0.1;
				}
			break;
			case 'R': temp *= 2;break;
			case 'S': temp = 0;	break;
		}
		if(ch[i-1]=='R'){
			temp *= 1.5;
		}
		sum += temp;
	} 
	
	printf("%d", sum);
	
	
	return 0;
}

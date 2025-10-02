//C6062

#include<stdio.h>

int main()
{
	int a1, a2, n;
	int a[1001];
	
	scanf("%d %d %d", &a1, &a2, &n);
	a[0] = a1;	a[1] = a2;
	
	int cnt=1, temp, i=1;
	
	while(cnt+1<n){
		temp = a[i-1] * a[i];	i++;
		if(temp>9){
			a[++cnt] = temp/10;
			a[++cnt] = temp%10;
		}else{
			a[++cnt] = temp;
		}
	}
	
	for(int i=0 ; i<n ; i++){
		if(i==0){
			printf("%d", a[i]);
		}else{
			printf(" %d", a[i]);
		}
	}
	
	return 0;
}

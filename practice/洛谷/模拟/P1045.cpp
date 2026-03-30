//P1045

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int p; cin >> p;
	long long arr[500] = {1,};
	int cnt = p*log10(2) + 1;
	int pos=1;
	long long  fac=2;
	
	while(p){
		int t=0;								// 1121 需要一个高精度快速幂 
		
		if(p & 1){ 
		 
			for(int j=0 ; j<pos && j<500 ; ++j){
				arr[j] = t + arr[j]*fac;
				t = arr[j] / 10;
				arr[j] %= 10;
			}
			
			while(t){
				if(pos>499) break;
				arr[pos++] = t % 10;
				t /= 10;
			}
		}
		 
		fac *= fac;
		p >>= 1;
	}
	
	if(arr[0]) --arr[0];
	else{
		int i;
		for(i=0 ; arr[i] ; ++i)	arr[i] = 9;
		--arr[i];
	}
	
	cout << cnt;
	
	for(int i=499 ; i>=0 ; --i){
		if((i+1)%50==0) cout << '\n';
		
		cout << arr[i];
	}
	
	return 0;
} 


/*
 
*/

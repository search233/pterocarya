//P1009

#include<iostream>

using namespace std;

int main()
{
	int n; cin >> n;
	
	int fac[110] = {1,};
	int out[110] = {0};
	
	for(int i=1 ; i<=n ; ++i){
		
		int temp=0;
		for(int j=0 ; j<=100 ; ++j){
			fac[j] = fac[j]*i + temp;
			temp = fac[j] / 10;
			fac[j] %= 10;
		}
		
		temp=0;
		for(int j=0 ; j<=100 ; ++j){
			out[j] = fac[j] + temp + out[j];
			temp = out[j] / 10;
			out[j] %= 10;
		}
	}
	
	int pos;
	for(pos=100 ; out[pos]==0 ; --pos);
	
	for( ; pos>=0 ; --pos){
		cout << out[pos];
	}
	
	return 0;
}


/*


*/

//P1591

#include<iostream>

using namespace std;

int main()
{
	
	int t, n, a;
	cin >> t;
	
	for(int i=0 ; i<t ; ++i){
		cin >> n >> a;
		int temp=0, cnt=0, k, pos=1;
		
		int num[3000] = {1,};
		
		for(int j=1 ; j<=n ; ++j){
			for(k=0 ; k<pos ; ++k){
				num[k] = num[k] * j + temp;
				temp = num[k] / 10;
				num[k] %= 10;
			}
			
			while(temp){
				num[k++] = temp % 10;
				temp /= 10;
				pos = k;
			}
		}
		
		for( --k ; k>=0 ; --k)	if(num[k]==a) ++cnt;
		
		cout << cnt << '\n';
	}
	
	return 0;
}

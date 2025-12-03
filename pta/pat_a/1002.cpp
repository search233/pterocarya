//1002

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double a[1001]={0};
	double res[1001]={0};
	
	int k; cin >> k;
	
	for(int i=0 ; i<k ; ++i){
		int n; cin >> n;
		cin >> a[n];
	}
	
	
	cin >> k;
	for(int i=0 ; i<k ; ++i){
		int n; cin >> n;
		double t; cin >> t;
		a[n] += t;
	}
	
	int cnt=0;
	for(int i=1000 ; i>=0 ; --i){
		if(a[i] > 0.44 || a[i] < -0.44){
			res[i] = a[i];
			++cnt;
		}
	}
	
	cout << cnt;
	for(int i=1000 ; i>=0 ; --i)
		if(res[i]) printf(" %d %.1f", i, res[i]);
	
	
	return 0;
}

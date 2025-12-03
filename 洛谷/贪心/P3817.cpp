//P3817

#include<iostream>
#include<vector>
#define ll long long

using namespace std;

int main(){
	int n; ll x;	cin >> n >> x;
	vector<ll> a(n);
	
	for(int i=0 ; i<n ; i++) cin >> a[i];
	
	ll sum = 0;
	
	for(int i=1 ; i<n ; i++){
		if(a[i]+a[i-1]>x){
			ll temp = a[i] + a[i-1] - x;
			a[i] > temp ? a[i]-=temp : (a[i-1]-=temp-a[i], a[i]=0);
			sum += temp;
		}
	}
	
//	for(int i=0 ; i<n ; i++) cout << a[i] << " ";
	cout << sum << endl;
	
	return 0;
}

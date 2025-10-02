//P1226

#include <iostream>

using namespace std;
typedef long long ll;

ll pow(ll a, ll b, ll p){
	ll ans=1;
	a %= p;
	while(b){
		ll t = a % p;
		if(b&1) ans *= t;
		ans %= p;
		a = t*t;
		b >>= 1;
	}
	return ans;
}

int main()
{
	ll a, b, p;
	cin >> a >> b >> p;
	
	cout << a << '^' << b;
	cout << " mod " << p;
	cout << '=' << pow(a,b,p)%p;
	
	return 0;
}

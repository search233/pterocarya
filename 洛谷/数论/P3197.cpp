//P3197

#include <iostream>

using namespace std;

typedef long long ll;

ll mod = 100003;
ll m, n;

ll pow(ll a, ll b){
	a %= mod;
	ll ans = 1;
	while(b){
		if(b&1){
			ans *= a;
			ans %= mod;
		}
		b >>= 1;
		a *= a;
		a %= mod;
	}
	
	return ans%mod;
}

int main()
{
	cin >> m >> n;
	
	ll num1 = pow(m,n);
	ll num2 =  (pow(m-1,n-1)*m%mod)%mod;
	cout << ((num1 - num2) % mod + mod) % mod;
	
	return 0;
}

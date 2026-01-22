#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

vector<ll> f(1e6 + 10, 1), inv(1e6 + 10, 1);

ll qpow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll C(ll n,ll m){
	if(n<m)
		return 0;
	return f[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve()
{
	ll n; cin >> n;
	vector<ll> a(n + 1, 0);
	for(auto &i : a){
		cin >> i;
	}

	ll maxn = 0;
	for (ll i = 1; i <= n;i++){
		maxn = max(maxn, a[i]);
	}
	ll cnt = 0;
	for (ll i = 1; i <= n;i++){
		if(a[i]<maxn){
			a[0] -= maxn - 1 - a[i];
			a[i] = maxn - 1;
			cnt++;
		}
	}
	// cout << cnt << ' ' << a[0] << endl;
	if(a[0]<0){
		return cout << 0 << endl, void();
	}
	if(cnt<=a[0]){
		return cout << f[n] << endl, void();
	}
	// cout << n - cnt << ' ' << cnt - a[0] << ' ';
	cout << f[n - cnt] * f[cnt] % mod * C(n - cnt + a[0], a[0]) % mod << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (ll i = 1; i <= 1e6;i++){
		f[i] = f[i - 1] * i % mod;
		inv[i] = qpow(f[i], mod - 2);
	}

	ll _ = 1;
	cin >> _;
	while (_--)
	{
		solve();
	}

	return 0;
}
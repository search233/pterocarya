//https://codeforces.com/problemset/problem/2104/D
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)6e6;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

bool vis[N + 9];
ll prime[N + 9];
ll psum[N + 9];

void work(){
    ll cnt = 0;

	for (int i=2 ; i<=N ; ++i){
		if(vis[i]==false)
			prime[++cnt] = i;

		for(int j=1 ; j<=cnt && prime[j]<=N/i ; ++j){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0)
				break;
		} 
	}

    for (int i=1 ; i<=N ; ++i) {
        psum[i] = psum[i-1] + prime[i];
    }


    // cout << prime[cnt] << '\n' << psum[cnt] ;

	return;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;

    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    int pos = 0;
    while (sum < psum[n-pos]) {
        sum -= a[pos];
        ++pos;
    }

    cout << pos << '\n';
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    work();

    while (_T--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*
*   /\_/\
*  (= ._.)
*  / >  \>
*/
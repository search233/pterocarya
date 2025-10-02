//https://ac.nowcoder.com/acm/contest/108304/J

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

ll ksm (ll _a, ll _b) {
    ll ans = 1;
    _a %= mod;
    while (_b) {
        if (_b & 1) ans = ans * _a % mod;
        _b >>= 1;
        _a = _a * _a % mod;
    }

    return ans % mod;
}

ll f(pll a, pll c) {
    if (a.second > c.second) swap(a, c);
    ll e = __gcd(a.first, c.first);
    if (e == 1) return 1;
    return ksm(e, a.second) * f({a.first/e, a.second}, {e, c.second-a.second}) % mod;
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    pll x = pll{a, b};
    pll y = pll{c, d};

    cout << f(x, y) << '\n';
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*



  /\_/\
 (= ._.)
 / >  \>

*/
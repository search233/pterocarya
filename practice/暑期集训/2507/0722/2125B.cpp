//https://codeforces.com/problemset/problem/2125/B
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;

    ll num = gcd(a, b);

    a /= num;
    b /= num;

    if (a <= k && b <= k) cout << 1 << '\n';
    else cout << 2 << '\n';
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--)
        solve();

    return 0;
}

//https://codeforces.com/problemset/problem/2122/B
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
    int n; cin >> n;

    ll ans = 0;
    ll a, b, c, d;

    for (int i=0 ; i<n ; ++i) {
        cin >> a >> b >> c >> d;
    
        int cnt0 = 0;
        int cnt1 = 0;

        if (a > c) {
            cnt0 = a - c;
            ans += cnt0;
        }
            

        if (b > d) {
            cnt1 = b - d;
            ans += min(a, c) + cnt1;
        }
    }

    cout << ans << '\n';
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

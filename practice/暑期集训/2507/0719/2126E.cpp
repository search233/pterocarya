//https://codeforces.com/problemset/problem/2126/E
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

ll s[M];
ll p[M];
ll a[M];

void solve() {
    int n;
    cin >> n;

    for (int i=0 ; i<n ; ++i)
        cin >> p[i];

    for (int i=0 ; i<n ; ++i)
        cin >> s[i];

    for (int i=0 ; i<n ; ++i) {
        a[i] = lcm(s[i], p[i]);
        // cout << a[i] << ' ';
    }
    
    int fix_gcd = 0;

    for (int i=0 ; i<n ; ++i) {
        fix_gcd = gcd(fix_gcd, a[i]);
        if (fix_gcd != p[i]) {
            cout << "NO\n";
            return;
        }
    }

    fix_gcd = 0;
    for (int i=n-1 ; i>=0 ; --i) {
        fix_gcd = gcd(fix_gcd, a[i]);
        if (fix_gcd != s[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
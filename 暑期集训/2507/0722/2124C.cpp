//https://codeforces.com/problemset/problem/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)6e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

int a[N];

void solve() {
    int n; cin >> n;

    int ans = 1;
    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
        if (i > 0)
            ans = lcm(a[i-1] / gcd(a[i-1], a[i]), ans);
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

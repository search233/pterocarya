//https://codeforces.com/problemset/problem/2106/D

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
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int> b(m + 1);

    for (int i=1 ; i<=n ; ++i) cin >> a[i];
    for (int i=1 ; i<=m ; ++i) cin >> b[i];

    int pos = 1;
    for (int i=1 ; i<=n ; ++i) {
        if (b[pos] <= a[i]) ++pos;
        if (pos > m) {
            cout << 0 << '\n';
            return;
        }
    }

    if (m == 1) {
        cout << b[1] << '\n';
        return;
    }

    pos = 1;
    vector<int> p(m+1, 0);
    for (int i=1 ; i<=m ; ++i) {
        while (pos <= n && b[i] > a[pos])   
            ++pos;

        if (pos > n) break;

        p[i] = pos;
        ++pos;
    }

    pos = n;
    vector<int> s(m+1, 0);
    for (int i=m ; i>0 ; --i) {
        while (pos > 0 && b[i] > a[pos])
            --pos;

        if (pos <= 0) break;

        s[i] = pos;
        --pos;
    }

    int res = INT_MAX;
    for (int i=1 ; i<=m ; ++i) {

        if (i == 1 && s[i+1])
            res = min(res, b[i]);

        else if (i == m && p[i-1])
            res = min(res, b[i]);

        else if (i>1 && i<m && p[i-1] < s[i+1] && p[i-1] && s[i+1])
            res = min(res, b[i]);
    }

    if (res != INT_MAX) cout << res << '\n';
    else cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--) {
        solve();
        // cout << "——————————————————" << '\n';
    }

    return 0;
}
/*

    for (int i=1 ; i<=m ; ++i) cout << p[i] << ' ';
    cout << '\n';

    for (int i=1 ; i<=m ; ++i) cout << s[i] << ' ';
    cout << '\n';

  /\_/\
 (= ._.)
 / >  \>

*/
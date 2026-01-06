//https://atcoder.jp/contests/abc415/tasks/abc415_c
//https://codeforces.com/problemset/problem/ /
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

int cmp(array<ll, 2> a, array<ll, 2> b) {
    if ((a[0] - a[1]) != (b[0] - b[1]))
    return (a[0] - a[1]) < (b[0] - b[1]);
    else  return a[0] > b[0];
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<array<ll, 2>> a;

    ll ans = 0;
    for (int i=0 ; i<m ; ++i) {
        ll A, B;
        cin >> A >> B;

        a.push_back({A, B});
    }

    sort (a.begin(), a.end(), cmp);

    for (int i=0 ; i<a.size() ; ++i) {

        if (n < a[i][0]) continue;

        ll x = a[i][0] - a[i][1];

        ll tnum = (n - a[i][0]) / x;

        n -= x * tnum;

        if (n >= a[i][0]) {
            n -= x;
            ++tnum;
        }

        ans += tnum;
    }

    cout << ans;
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    // cin >> _T;

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
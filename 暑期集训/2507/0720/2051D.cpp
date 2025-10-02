//https://codeforces.com/problemset/problem/2051/D
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
    int n;
    ll x, y;

    cin >> n >> x >> y;

    vector<ll> a;

    ll sum = 0;
    for (int i=0 ; i<n ; ++i) {
        ll tnum; cin >> tnum;
        a.push_back(tnum);
        sum += tnum;
    }

    if (sum <= x) {
        cout << 0 << '\n';
        return;
    }

    ll minn = max(sum - y, 0ll);
    ll maxn = sum - x;

    sort(a.begin(), a.end());

    ll res = 0;

    for (int i=0 ; i<n-1 ; ++i) {
        ll tminn = minn-a[i];
        ll tmaxn = maxn-a[i];

        auto l = lower_bound(a.begin() + i+1, a.end(), tminn);
        auto r = upper_bound(a.begin() + i+1, a.end(), tmaxn); 
        if (l == a.end() || *(r-1) > tmaxn)
            continue;
        res += r - l;
        // cout << *l << ' ' << *(r-1) << ' ' << r - l <<'\n'; 
        
    }

    cout << res << '\n';
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

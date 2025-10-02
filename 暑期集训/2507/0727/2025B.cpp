//https://codeforces.com/problemset/problem/2025/B
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const ll mod =  (ll)1e9 + 7;
const ll INF = LLONG_MAX;

void solve() {
    int t; cin >> t;
    vector<ll> k;

    ll maxn = 0;
    for (int i=1 ; i<=t ; ++i) {
        ll tmp; cin >> tmp;
    }

    for (int i=0 ; i<t ; ++i) {
        ll tmp; cin >> tmp;
        k.push_back(tmp);
        maxn = max(maxn, tmp);
    }

    vector<ll> res;
    res.push_back(1);
    for (int i=1 ; i<=maxn ; ++i) 
        res.push_back((res.back() << 1ll) % mod);

    for (int i=0 ; i<t ; ++i) {
        cout << res[k[i]] << '\n';
    }
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
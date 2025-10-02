//https://codeforces.com/problemset/problem/2114/D
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

int cmp1(pii a, pii b) { return a.first < b.first; }
int cmp2(pii a, pii b) { return a.second < b.second; }

void solve()
{
    ll n; cin >> n;
    vector<pii> p;
    multiset<int> x;
    multiset<int> y;

    for (int i=0 ; i<n ; ++i) {
        int xi, yi;
        cin >> xi >> yi;

        p.push_back({xi, yi});
        x.insert(xi);
        y.insert(yi);
    }

    ll w = *x.rbegin() - *x.begin() + 1;
    ll h = *y.rbegin() - *y.begin() + 1;

    ll S = w * h;

    if ( S > n ) {
        for (int i=0 ; i<n ; ++i) {
            x.erase(x.find(p[i].first));
            y.erase(y.find(p[i].second));

            w = *x.rbegin() - *x.begin() + 1;
            h = *y.rbegin() - *y.begin() + 1;

            ll ts = w * h;
            if ( ts <= n-1 ) ts += min(w, h);

            S = min(S, ts); 
            x.insert(p[i].first);
            y.insert(p[i].second);
        }
    }

    cout << S << '\n';
    // cout << '\n';
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
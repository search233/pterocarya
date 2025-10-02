//https://codeforces.com/problemset/problem/2124/B
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
    vector<ll> a;
    vector<ll> minn;
    vector<ll> psum;

    int n; cin >> n;

    for (int i=0 ; i<n ; ++i) {
        ll tmp; cin >> tmp;

        a.push_back(tmp);

        if (i == 0) {
            minn.push_back(tmp);
            psum.push_back(tmp);
        } else {
            minn.push_back(min(minn.back(), tmp));
            psum.push_back(psum.back() + minn.back());
        }
    }

    ll ans = psum.back();
    for (int i=1 ; i<n ; ++i) {

        ll tmp = a[i] + a[i-1];

        if (i == 1)
            ans = min(ans, tmp);
        else
           ans = min(ans, psum[i-2] + min(minn[i - 2], tmp));
        
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

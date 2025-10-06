//https://codeforces.com/problemset/problem/1994/C
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

ll x;
ll a[N], res[N];
vector<ll> psum;

ll find(vector<ll>::iterator l){
    ll tag = x + *(l-1);
    auto it = upper_bound(l, psum.end(), tag);

    if (it < psum.end()-1)
        return res[(it-psum.begin()) + 1] + (it - l);
    else
        return it - l;
}


void solve() {
    int n;
    cin >> n >> x;

    psum.resize(n+1, 0);

    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        psum[i] = a[i] + psum[i-1];
    }

    ll ans = 0;
    for (int i=n ; i>0 ; --i) {
        res[i] = find(psum.begin() + i);        

        ans += res[i];
    }
    
    cout << ans << '\n';

    // for (int i=1 ; i<=n ; ++i) {
    //     cout << res[i] << ' ';
    // }

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

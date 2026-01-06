//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
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
    vector<int> a(n + 1);

    for (int i=1 ; i<=n ; ++i) 
        cin >> a[i];


    int tag = 1;
    ll ans = 0;
    vector<string> g(n + 1);

    for (int k=0 ; k<=35 && tag ; ++k) {

        tag = 0;
        ll cnt1[2] = {0};
        ll cnt0[2] = {0};

        for (int i=1 ; i<=n ; ++i) {

            if (a[i]) tag = 1;
            int tcnt = 0;
            for (auto it : g[i])
                if (it == '1') 
                    ++tcnt;
            
            if (a[i] & 1) {
                ++cnt1[tcnt & 1];
                g[i] += '1';
            } else {
                ++cnt0[tcnt & 1];
                g[i] += '0';
            }

            a[i] >>= 1;
        }

        ans += (cnt1[0] * cnt0[0] + cnt1[1] * cnt0[1]) * (1ll << k);
    }

    cout << ans << '\n';
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

        cout << k << ' ' << ans << '\n';
            cout << cnt0[0] << ' ' 
                 << cnt1[0] << ' '
                 << cnt0[1] << ' '
                 << cnt1[1] << '\n';

        cout << "-----------" << '\n';

*   /\_/\
*  (= ._.)
*  / >  \>
*/
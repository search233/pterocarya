//https://codeforces.com/problemset/problem/2031/D
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)5e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

int a[N];
int pmax[N];
int ans[N];

void solve() {
    int n; cin >> n;

    pmax[0] = -1;
    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        pmax[i] = max(a[i], pmax[i-1]);
    }

    int minn = a[n];
    int maxn = pmax[n];

    ans[n] = pmax[n];
    for (int i=n-1 ; i>0 ; --i) {
        if (pmax[i] <= minn)
            maxn = pmax[i];
        
        ans[i] = maxn;

        minn = min(minn, a[i]);
    }

    for (int i=1 ; i<=n ; ++i) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
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

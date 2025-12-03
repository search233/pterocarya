//https://codeforces.com/problemset/problem/2123/C
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

    vector<int> a(n+1);
    vector<int> minn(n+1);
    vector<int> maxn(n+1);

    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        if (i == 1) minn[i] = a[i];
        else minn[i] = min(minn[i-1], a[i]);
    }

    for (int i=n ; i>0 ; --i) {
        if (i == n) maxn[i] = a[i];
        else maxn[i] = max(maxn[i+1], a[i]);
    }

    vector<int> res(n+1);
    for (int i=1 ; i<=n ; ++i) {
        if (a[i] == maxn[i] || a[i] == minn[i])
            cout << 1;
        else cout << 0;
    }

    cout << '\n';
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

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
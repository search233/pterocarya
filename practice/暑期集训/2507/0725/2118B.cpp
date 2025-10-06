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


void solve() {
    int n; cin >> n;

    vector<array<int, 3>> res;

    for (int i=2 ; i<=n ; ++i) {
        res.push_back({i, 1, i});
    }

    for (int i=1, j=2 ; i<=n-2 ; ++i, ++j) {
        res.push_back({i, j, n});
    }

    cout << res.size() << '\n';
    for (auto [i, l, r] : res) {
        cout << i << ' '
             << l << ' '
             << r << '\n';
    }
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
/*
*   /\_/\
*  (= ._.)
*  / >  \>
*/
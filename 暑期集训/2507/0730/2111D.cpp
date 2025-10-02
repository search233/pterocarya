//https://codeforces.com/problemset/problem/2111/D
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
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    for (int i=0 ; i<m ; ++i) {
        cin >> a[i];
    }

    sort (a.begin(), a.end());

    vector<array<int, 6>> res(n);

    int l = 0;
    int r = m - 1;

    for (int i=0 ; i<n ; ++i) {
        cout << a[r] << ' '
             << a[l] << ' '
             << a[r] << ' '
             << a[l] << ' '
             << a[r] << ' '
             << a[l] << '\n';

        if (i < n-1) {
            cout << a[l] << ' '
                 << a[r] << ' '
                 << a[l] << ' '
                 << a[r] << ' '
                 << a[l] << ' '
                 << a[r] << '\n';
                 
            ++l;
            --r;
            ++i;
        }
    }

    
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
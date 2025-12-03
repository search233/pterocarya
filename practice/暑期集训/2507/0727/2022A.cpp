//https://codeforces.com/problemset/problem/2022/A
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
    int n, r;
    cin >> n >> r;

    int cnt = 0;
    int ans = 0;
    for (int i=0 ; i<n ; ++i) {
        int tmp; cin >> tmp;

        if (tmp & 1)
            ++cnt;

        r -= (tmp>>1);
        ans += (tmp>>1) * 2;
    }

    // cout << ans << '\n';

    if (cnt <=r ) ans += cnt;
    else     ans += r*2 - cnt;

    cout << ans << '\n';
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
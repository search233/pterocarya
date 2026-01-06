//https://codeforces.com/problemset/problem/1064/B
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
    ll a; cin >> a;

    int cnt = 0;
    while (a) {
        if (a & 1)
            ++cnt;

        a >>= 1;
    }

    cout << (1ll << cnt) << '\n';
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



  /\_/\
 (= ._.)
 / >  \>

*/
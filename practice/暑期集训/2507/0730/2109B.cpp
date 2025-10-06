//https://codeforces.com/problemset/problem/2109/B
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

int cul(int x) {
    int cnt = 0;
    while (x > 1) {
        ++cnt;
        x = ((x + 1) >> 1);
    }

    return cnt;
}

void solve() {
    int m, n, a, b;

    cin >> n >> m >> a >> b;
    // cout << cul(n)+cul(min(b, m-b+1)) << ' ' << cul(m)+cul(min(a, n-a+1)) << '\n';
    cout << min(cul(n)+cul(min(b, m-b+1)), cul(m)+cul(min(a, n-a+1))) + 1 << '\n';
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
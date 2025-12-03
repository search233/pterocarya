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
    int n, s;
    cin >> n >> s;

    vector<int> a(n);

    int sum = 0;
    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if ((sum & 1) ^ (s & 1)) sum += 3;


    auto cmp = [&](int x, int y) -> bool {
        if (!x) return 0;
        if (!y) return 1;
        return x < y;
    };

    sort(a.begin(), a.end(), cmp);

    if (sum > s) { 
        for (auto ai : a) cout << ai << ' ';
        cout << '\n';
        return;
    }

    cout << -1 << '\n';
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
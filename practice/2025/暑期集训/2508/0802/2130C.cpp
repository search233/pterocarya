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

    vector<pii> g; 
    for (int i=1 ; i<=n ;++i) {
        int ta, tb;
        cin >> ta >> tb;

        g.push_back(pii{ta, tb});
    }

    auto cmp = [](pii a, pii b) -> bool {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    };
    
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
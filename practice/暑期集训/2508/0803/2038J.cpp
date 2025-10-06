//https://codeforces.com/problemset/problem/2038/J
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

    ll num = 0;
    for (int i=0 ; i<n ; ++i) {
        string s;
        int tmp;
        cin >> s >> tmp;

        if (s[0] == 'P') 
            num += tmp;
        else {
            if (num >= tmp) {
                cout << "NO\n";
                num -= tmp;
                continue;
            } else {
                cout << "YES\n";
                num = 0;
                continue;
            }
        }
    }

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



  /\_/\
 (= ._.)
 / >  \>

*/
//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/abc415/tasks/abc415_c/
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
    ll n; cin >> n;

    string s; cin >> s;
    s = ' ' + s;

    queue<ll> qu;

    ll num0 = (1ll << n) - 1ll;

    if (s[num0] == '1') {
        cout << "No\n";
        return;
    }

    qu.push(0);

    vector<ll> vis(num0+1, 0);

    while (!qu.empty()) {
        ll num = qu.front();
        qu.pop();

        for (int i=0 ; i<n ; ++i) {
            ll tmp = num | (1ll << i);

            if (s[tmp]=='1' || vis[tmp])
                continue;

            if (tmp == num0) {
                cout << "Yes\n";
                return;
            }
            
            vis[tmp] = 1;
            qu.push(tmp);            
        }
    }

    cout << "No\n";
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
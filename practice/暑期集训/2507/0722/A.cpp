//https://ac.nowcoder.com/acm/contest/108300/A

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

int f[1500];
int g[1500][1500];

void solve() {
    int n; cin >> n;

    for (int i=1 ; i<=n ; ++i) {
        cin >> f[i];
    } 

    queue<int> qu;

    for (int i=1 ; i<=n ; ++i) {
        for (int j=0 ; j<f[i] ; ++j) {
            qu.push(j);
        }

        while (qu.size() < i) qu.push(0);

        for (int j=1 ; j<=i ; ++j) {
            if (qu.front() == f[j]) {
                qu.push(qu.front());
                qu.pop();
            }
            g[i][j] = g[j][i] = qu.front();
            qu.pop();
        }
    }

    for (int i=1 ; i<=n ; ++i) {
        for (int j=1 ; j<=n ; ++j) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
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

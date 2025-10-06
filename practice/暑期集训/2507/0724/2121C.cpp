//https://codeforces.com/problemset/problem/2121/C

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

    vector<vector<int>> g(n+1, vector<int>(m+1, 0));

    int x, y;
    int cnt = 0;
    int maxn = 0;
    for (int i=1 ; i<=n ; ++i) {
        for (int j=1 ; j<=m ; ++j) {
            cin >> g[i][j];
            if (maxn < g[i][j]) {
                maxn = g[i][j];
                cnt = 0;
                x = i;
                y = j;
            }

            if (maxn == g[i][j]) ++cnt;
        }
    }

    if (cnt == 1) {
        cout << maxn - 1 << '\n';
        return;
    }

    if (cnt >= n + m) {
        cout << maxn << '\n';
        return;
    }

    int tcnt = 0;

    for (int i=1 ; i<=n ; ++i) {
        if (maxn == g[i][y]) ++tcnt;
        if (tcnt == cnt) {
            cout << maxn - 1 << '\n';
            return;
        }
    }

    for (int i=1 ; i<=n ; ++i) {
        int sum = 0;
        for (int j=1 ; j<=m ; ++j) {
            if (maxn == g[i][j]) ++sum;
        }
        if (g[i][y] == maxn) --sum;
        if (sum + tcnt == cnt) {
            cout << maxn - 1 << '\n';
            return; 
        }
    }

    tcnt = 0;

    for (int i=1 ; i<=m ; ++i) {
        if (maxn == g[x][i]) ++tcnt;
        if (tcnt == cnt) {
            cout << maxn - 1 << '\n';
            return;
        }
    }

    for (int j=1 ; j<=m ; ++j) {
        int sum = 0;
        for (int i=1 ; i<=n ; ++i) {
            if (maxn == g[i][j]) ++sum;
        }
        if (g[x][j] == maxn) --sum;
        if (sum + tcnt == cnt) {
            cout << maxn - 1 << '\n';
            return; 
        }
    }

    cout << maxn << '\n';
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

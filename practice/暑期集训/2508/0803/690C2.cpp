//https://codeforces.com/problemset/problem/690/C2
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

vector<int> g[M];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=1 ; i<=n ; ++i) {
        g[i].clear();
    }

    for (int i=0 ; i<m ; ++i) {
        int tu, tv;
        cin >> tu >> tv;

        g[tu].push_back(tv);
        g[tv].push_back(tu);
    }

    int  res = 0;

    queue<pii> qu;
    

    for (int i=1 ; i<=n ; ++i) {
        if (g[i].size() == 1) {
            qu.push(pii{i, 0});
            break;
        }
    }

    int pos = 0;

    vector<bool> vis(n + 1, 0);

    while (!qu.empty()) {
        auto [u, d] = qu.front();
        qu.pop();
        vis[u] = 1;

        if (g[u].size() == 1 && vis[g[u][0]]) {
            if (d > res) {
                res = d;
                pos = u;
            }
        } else {
            for (auto v : g[u]) {
                if (!vis[v]) 
                    qu.push(pii{v, d+1});
            }
        }
    }

    // cout << res << '\n';
    qu.push({pos, 0});
    for (int i=1 ; i<=n ; ++i) vis[i] = 0;


    while (!qu.empty()) {
        auto [u, d] = qu.front();
        qu.pop();
        vis[u] = 1;

        if (g[u].size() == 1 && vis[g[u][0]]) {
            res = max(res, d);
        } else {
            for (auto v : g[u]) {
                if (!vis[v]) 
                    qu.push(pii{v, d+1});
            }
        }
    }

    cout << res << '\n';

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
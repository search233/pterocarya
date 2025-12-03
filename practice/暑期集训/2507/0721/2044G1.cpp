//https://codeforces.com/problemset/problem/2044/G1
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

int r[N];
vector<int> g[N];

int incnt[N];

void solve() {
    int n; cin >> n;
    for (int i=1 ; i<=n ; ++i) {
        g[i].clear();
        incnt[i] = 0;
    }

    for (int i=1 ; i<=n ; ++i) {
        cin >> r[i];
        g[r[i]].push_back(i);
        ++incnt[r[i]];
    }


    queue<int> qu1;

    for (int i=1 ; i<=n ; ++i) {
        if (incnt[i] == 0) 
            qu1.push(i);
    }

    while (!qu1.empty()) {
        int pos = qu1.front();
        qu1.pop();

        --incnt[r[pos]];
        if (incnt[r[pos]] == 0)
            qu1.push(r[pos]);
    }

    queue<pii> qu2;
    for (int i=1 ; i<=n ; ++i) {
        if (incnt[i] != 0) 
            qu2.push({i, 0});
    }

    int res = 0;
    while (!qu2.empty()) {
        pii it = qu2.front();
        qu2.pop();

        for (int i=0 ; i<g[it.first].size() ; ++i) {
            if (incnt[g[it.first][i]] == 0) {
                res = max(res, it.second+1);
                qu2.push({g[it.first][i], it.second+1});
            }
        }
    }

    cout << res + 2 << '\n';
    
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

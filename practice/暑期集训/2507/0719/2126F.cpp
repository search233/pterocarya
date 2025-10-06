//https://codeforces.com/problemset/problem/2126/F
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, ll>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

pii fa[N]; //{p, c} 父节点, 边权
int a[N]; //颜色
vector<pii> g[N]; //存图
vector<map<int, ll>> acnt; //每个节点的子节点的不同颜色的变化值

void bfs(int p, ll& res) {
    queue<int> qu;
    qu.push(p);
    fa[p].first = -1;
    fa[p].second = -1;

    while (!qu.empty()) {

        int u = qu.front();
        qu.pop();

        for (int i=0 ; i<g[u].size() ; ++i) {
            int v = g[u][i].first;
            int c = g[u][i].second;

            if (!fa[v].first) {
                qu.push(v);

                if (a[u] != a[v])
                    res += c;

                acnt[u][a[v]] += c;

                fa[v].first = u;
                fa[v].second = c;
            }
        }
    }
}

void solve() {
    ll res = 0;
    int n, q;
    cin >> n >> q;

    acnt.clear();
    acnt.resize(n+1);

    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        fa[i].first = 0;
        fa[i].second = 0;
        g[i].clear();
        // acnt[i] = {-1, -1};
    }
        
    //建图
    for (int i=1 ; i<n ; ++i) {
        int u, v, c;
        cin >> u >> v >> c;

        g[u].push_back(pii{v, c});
        g[v].push_back(pii{u, c});
    }

    //扫一遍，确定树上关系，计算初始值
    bfs(1, res);

    // cout << res << '\n';

    // for (int i=1 ; i<=n ; ++i) {
    //     cout << i << '\n';
    //     cout << fa[i].first << ' ' << fa[i].second << '\n';
    //     for (auto num : acnt[i]) {
    //         cout << num.first << ' ' << num.second << '\n';
    //     }
    //     cout << '\n';
    // }

    for (int i=0 ; i<q ; ++i) {
        int p, x;
        cin >> p >> x;

        //颜色不同时
        if (a[p] != x) {
            //计算子节点对其影响
            res += acnt[p][a[p]];
            res -= acnt[p][x];
            //查看父节点颜色
            if (fa[p].first != -1) {
                if (a[fa[p].first] == a[p]) {
                    res += fa[p].second;

                } else if (a[fa[p].first] == x) {
                    res -= fa[p].second;
                }
                //更新父节点的 子节点颜色表
                acnt[fa[p].first][a[p]] -= fa[p].second;
                acnt[fa[p].first][x] += fa[p].second;
            }

            a[p] = x;
        }

        cout << res << '\n';
    }

    // cout << '\n';
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

        // for (int i=0 ; i<g[p].size() ; ++i) {
        //     auto v = g[p][i]; 
        //     if (a[v.first] == a[p] && x != a[v.first])
        //         res += v.second;
        //     else if (a[v.first] != a[p] && x == a[v.first])
        //         res -= v.second;
        // }
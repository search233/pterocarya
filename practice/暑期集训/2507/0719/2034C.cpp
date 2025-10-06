//https://codeforces.com/problemset/problem/2034/C
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)1e3 + 9;
const int M = (int)1e3 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

int n, m;
char dir[4] = {'U','L','D','R'};
int vis[N][M]; // 0:未走 1:不可出 2:正在走 -1:可出
vector<string> graph;

int dfs(int x, int y) {

    if (x < 0 || y < 0 || x >= n || y >= m)
        return -1;

    int res = vis[x][y];

    if (res > 0) return 1;
    else if (res < 0) return -1;
    
    vis[x][y] = 2;

    //方向固定时，路上的结果固定
    if (graph[x][y] == dir[0]) {  
        res = dfs(x-1, y);

    } else if (graph[x][y] == dir[2]) {
        res = dfs(x+1, y);

    } else if (graph[x][y] == dir[1]) {
        res = dfs(x, y-1);

    } else if (graph[x][y] == dir[3]) {
        res = dfs(x, y+1);

    } else {

        res = max(max(res, -1), dfs(x-1, y));
        res = max(max(res, -1), dfs(x+1, y));
        res = max(max(res, -1), dfs(x, y-1));
        res = max(max(res, -1), dfs(x, y+1));
    }

    vis[x][y] = res;
    // cout << "cao" << '\n';
    return res;
}

void solve() {

    cin >> n >> m;

    for (int i=0 ; i<n ; ++i) {
        string s; cin >> s;
        graph.push_back(s);

        for (int j=0 ; j<m ; ++j) 
            vis[i][j] = 0;
    }

    int ans = 0;

    dfs(0, 0);

    for (int i=0 ; i<n ; ++i) {
        for (int j=0 ; j<m ; ++j) {
            
            if (vis[i][j] == 0)
                dfs(i, j);

            if (vis[i][j] == 1)
                ++ans;
            // cout << vis[i][j] << ' ';
        }
        // cout << '\n';
    }

    cout << ans << '\n';

    graph.clear();
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
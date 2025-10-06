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

int g[1000][1000];
int dx[4] = {0, 1,  0, -1};
int dy[4] = {1, 0, -1,  0};

void solve() {
    int n; cin >> n;

    for (int i=0 ; i<n ; ++i) {
        for (int j=0 ; j<n ; ++j) 
            g[i][j] = 0;
    }

    int cnt = n * n - 1;

    int dir = 0;
    queue<pii> qu;

    qu.push({0, 0});

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        g[x][y] = cnt--;
        if (cnt < 0) break;

        int xx = x + dx[dir];
        int yy = y + dy[dir];

        if (xx < 0  || xx >=n || yy < 0 || yy >=n || g[xx][yy] != 0) {
            ++dir;
            dir %= 4;

            xx = x + dx[dir];
            yy = y + dy[dir];
        }

        qu.push({xx, yy});
    }

    for (int i=0 ; i<n ; ++i) {
        for (int j=0 ; j<n ; ++j) {
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
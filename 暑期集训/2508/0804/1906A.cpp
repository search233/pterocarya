//https://codeforces.com/problemset/problem/1906/A

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

string g[3];
int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
int vis[3][3];

void solve() {

    for (int i=0 ; i<3 ; ++i) {
        cin >> g[i];
    }

    string res;
    res = "CCC";

    char ch = 'C';
    vector<pii> pos;

    auto search = [&](int x, int y) -> char {
        ch = 'C';
        int xx, yy;
        for (int i=0 ; i<8 ; ++i) {
            xx = x + dx[i];
            yy = y + dy[i];

            if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3 || vis[xx][yy])
                continue;

            if (ch > g[xx][yy]) ch = g[xx][yy];
        }

        return ch;
    };

    for (int i=0 ; i<3 ; ++i) {
        for (int j=0 ; j<3 ; ++j) {

            if (ch > g[i][j]) {
                pos.clear();
                pos.push_back(pii{i, j});
                ch = g[i][j];

            } else if (ch == g[i][j])
                pos.push_back(pii{i, j});
        } 
    }

    res[0] = ch;

    for (auto [x, y] : pos) {
        string tres = "CCC";
        tres[0] = g[x][y];

        for (int i=0 ; i<3 ; ++i)
            for (int j=0 ; j<3 ; ++j)
                vis[i][j] = 0;

        vis[x][y] = 1;

        tres[1] = min(search(x, y), tres[1]);

        vector<pii> pos2;

        for (int i=0 ; i<8 ; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3 || vis[xx][yy])
                continue;

            if (tres[1] == g[xx][yy]) pos2.push_back(pii{xx, yy});
        }

        for (auto [x2, y2] : pos2) {
            vis[x2][y2] = 1;

            tres[2] = min(search(x2, y2), tres[2]);

            vis[x2][y2] = 0;
        }

        res = min(res, tres);
    }

    cout << res;
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


        while (!qu.empty()) {
            for (int i=0 ; i<8 ; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3 || vis[xx][yy])
                continue;

            qu.push()
        }

  /\_/\
 (= ._.)
 / >  \>

*/
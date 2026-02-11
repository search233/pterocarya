//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = ' ' + s[i] + ' ';
    }

    vector a(n + 2, vector<int> (m + 2));

    vector<arr2> p1;
    vector<arr2> p2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = s[i][j] - '0';
            if (a[i][j] == 1) p1.push_back({i, j});
            else if (a[i][j] == 2) p2.push_back({i, j});
        }
    }

    vector vis(n + 2, vector<int> (m + 2));

    auto f = [&](arr2 p) -> bool {
        if (p[0] > n || p[0] < 1 || p[1] > m || p[1] < 1) {
            return false;
        }
        if (vis[p[0]][p[1]] != 0) return false;
        return true;
    };
    
    auto ck = [&](arr2 p1, arr2 p2) -> bool {
        queue<arr2> qu;
        qu.push(p1);
        vis[p1[0]][p1[1]] = 1;

        while (!qu.empty()) {
            int x = qu.front()[0];
            int y = qu.front()[1];
            qu.pop();

            for (int i = 0; i < 4; ++i) {
                arr2 p = {x + dx[i], y + dy[i]};
                if (p == p2) return true;

                if (f(p) && vis[x + dx[i]][y + dy[i]] == 0) {
                    qu.push(p);
                    vis[p[0]][p[1]] = 1; 
                }
            }
        }

        return false;
    };

    auto find = [&](arr2 p1, arr2 p2) -> bool {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                vis[i][j] = 0;
            }
        }

        vector pre(n + 2, vector<arr2> (m + 2, {-1, -1}));
        queue<arr2> qu;
        qu.push(p1);
        pre[p1[0]][p1[1]] = p1;

        while (!qu.empty()) {
            int x = qu.front()[0];
            int y = qu.front()[1];

            if (qu.front() == p2) {
                while (!(x == p1[0] && y == p1[1])) {
                    vis[x][y] = 1;
                    x = pre[x][y][0];
                    y = pre[x][y][1];
                }
                vis[x][y] = 1;
                return true;
            }

            qu.pop();

            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                arr2 p = {xx, yy};

                if (f(p) && pre[xx][yy][0] == -1) {
                    qu.push(p);
                    pre[xx][yy] = {x, y};
                }
            }
        }

        return false;
    };

    if (find(p1[0], p1[1]) && ck(p2[0], p2[1])) {
        cout << "YES\n";
    }
    else if (find(p2[0], p2[1]) && ck(p1[0], p1[1])) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
} 

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------\n";
    }

    return 0;
}
/*
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │              
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐    
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │    
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
│Ctrl │Win │Alt │         Space         │Alt │ Fn │Menu│Ctrl│ │ ← │ ↓ │ → │
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

*/

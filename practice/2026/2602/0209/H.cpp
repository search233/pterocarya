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
using arr3 = array<ll, 3>;
const double PI = acos(-1.0);

int dx[13] = {0, -2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1 ,2};
int dy[13] = {0, 0,  -1,  0,  1, -2, -1, 1, 2, -1, 0, 1, 0};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    arr3 mxp = {0, 0, 0};
    vector a(n + 2, vector<ll> (m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] > mxp[2]) {
                mxp[0] = i;
                mxp[1] = j;
                mxp[2] = a[i][j];
            }
        }
    }

    auto f = [&](int x, int y) -> bool {
        if (x < 1 || x > n || y < 1 || y > m) {
            return false;
        }
        return true;
    };

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ll sum = 0;
            for (int k = 0; k < 13; ++k) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (f(xx, yy)) {
                    sum += a[xx][yy];
                }
            }
            if (sum > mxp[2]) {
                mxp[0] = i;
                mxp[1] = j;
                mxp[2] = sum;
                // cout << 1 << ' ' <<  i << ' ' << j << '\n';
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int x, y;
        ll z;
        cin >> x >> y >> z;

        a[x][y] += z;

        for (int k = 0; k < 13; ++k) {
            int xx = x - dx[k];
            int yy = y - dy[k];
            ll sum = 0;
            if (!f(xx, yy)) continue;

            for (int k = 0; k < 13; ++k) {
                int xxx = xx + dx[k];
                int yyy = yy + dy[k];
                if (f(xxx, yyy)) {
                    sum += a[xxx][yyy];
                }
            }
            if (sum > mxp[2]) {
                mxp[0] = xx;
                mxp[1] = yy;
                mxp[2] = sum;
            // cout <<2 << ' ' <<  x << ' ' << y << '\n';
            }
        }

        cout << mxp[0] << ' ' << mxp[1] << '\n';
    }


} 

int main() {
    
    __BUFF__

    int _ = 1;
    // cin >> _;

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

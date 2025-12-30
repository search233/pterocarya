//https://codeforces.com/problemset/problem/2185/F

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void solve() {
    int n, q; cin >> n >> q;
    int len = (1 << n);

    queue<int> qu;
    vector<arr3> tree(len << 2);

    for (int i = 1; i <= len; ++i) {
        cin >> tree[i][1];
        qu.push(i);
    }    

    int cnt = len;

    while (qu.size() > 1) {
        ++cnt;

        int ls = qu.front();
        qu.pop();
        int rs = qu.front();
        qu.pop();

        tree[ls][2] = rs;
        tree[rs][2] = ls;

        tree[ls][0] = tree[rs][0] = cnt;
        tree[cnt][1] = tree[ls][1] ^ tree[rs][1];
        
        qu.push(cnt);    
    }

    tree[cnt][0] = -1;

    auto f = [&](int b, int c) -> int {
        int sum = 0;
        int pos = b;
        int num = 1;

        while (tree[pos][0] != -1) {
            tree[pos][1] = c;
            int brop = tree[pos][2];
            int broc = tree[brop][1];

            if (c < broc || (c == broc && pos > brop)) {
                sum += num;
            }

            pos = tree[pos][0];
            num <<= 1;
            c = c ^ broc;
        }

        return sum;
    };

    for (int i = 0; i < q; ++i) {
        int b, c;
        cin >> b >> c;

        int cc = tree[b][1];
        cout << f(b, c) << '\n';

        f(b, cc);
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
│ Tab │ Q │ W │ tree │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│
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
//https://codeforces.com/problemset/problem/339/D

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
    int n, m;
    cin >> n >> m;

    n = (1 << n);
    vector<int> fa(n * 4);
    vector<int> tree(n * 4);
    queue<arr2> qu;

    for (int i = 0; i < n; ++i) {
        cin >> tree[i + 1];
        qu.push({i + 1, 1});
    }

    int cnt = n + 1;
    while (!qu.empty()) {
        auto [i, d] = qu.front();
        qu.pop();

        if (qu.empty()) {
            tree[cnt] = tree[i];
            break;
        }

        if (d & 1) tree[cnt] = (tree[i] | tree[i + 1]);
        else tree[cnt] = (tree[i] ^ tree[i + 1]);
        fa[i] = fa[i + 1] = cnt;
        // cout << cnt << ' ' << tree[cnt] << '\n';

        qu.pop();
        qu.push({cnt, d + 1});
        ++cnt;
        
    }

    --cnt;
    for (int i = 0; i < m; ++i) {
        int p, b;
        cin >> p >> b;

        tree[p] = b;
        int d = 1;
        while (p != cnt) {
            int pp = p + ((p & 1) ? 1 : -1);
            
            if (d & 1) {
                tree[fa[p]] = tree[p] | tree[pp];
            }
            else {
                tree[fa[p]] = tree[p] ^ tree[pp];
            }

            p = fa[p];
            ++d;
        }

        cout << tree[cnt] << '\n';
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

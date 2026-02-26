//https://codeforces.com/problemset/problem/2188/D

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
    int x, y;
    cin >> x >> y;
    
    auto f = [](int a, int b) -> int {
        if (a & b == 0) 
            return a;

        int cnt = 0;
        int a2 = a;
        while (a2) {
            ++cnt;
            a2 >>= 1;
        }

        while (cnt <= 31 && ((b >> cnt) & 1)) ++cnt;
        a2 = (1 << cnt);


        int a1 = a;
        int aa = 0;
        int tag = 0;

        for (int i = 31; i >= 0; --i) {            
            int pa = ((a1 >> i) & 1);
            int pb = ((b >> i) & 1);

            if (pa == 1) {
                aa += (1 << i);
            }

            if (pa & pb == 1) {
                a1 -= (1 << i);
                aa -= (1 << i);
                tag = 1;
            }
            if ((pa | pb) == 0) {
                if (tag) a1 += (1 << i);
                if (aa + (1 << i) > a && aa + (1 << i) - a < abs(a2 - a)) {
                    a2 = aa + (1 << i);
                }
            }
        }

        if (a2 - a < a - a1) {
            return a2;
        }
        else {
            return a1;
        }
    };

    int p = f(x, y);
    int q = f(y, x);

    if (abs(q - y) < abs(p - x)) {
        cout << x << ' ' << q << '\n';
    }
    else {
        cout << p << ' ' << y << '\n';
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

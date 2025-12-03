//https://codeforces.com/problemset/problem/2163/C

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

void solve() {
    int n; cin >> n;

    vector<arr2> a(n);

    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i][j];
        }
    }

    vector<arr2> pre(n, {INT_MAX, 0}), sub(n, {INT_MAX, 0});

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            pre[i][0] = pre[i][1] = a[i][0];
            continue;
        }
        pre[i][0] = min(pre[i - 1][0], a[i][0]);
        pre[i][1] = max(pre[i - 1][1], a[i][0]);
        // cout << pre[i][0] << ' ' << pre[i][1] << '\n';
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            sub[i][0] = sub[i][1] = a[i][1];
            continue;            
        }
        sub[i][0] = min(sub[i + 1][0], a[i][1]);
        sub[i][1] = max(sub[i + 1][1], a[i][1]);
    }

    vector<arr2> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i][0] = min(pre[i][0], sub[i][0]);
        ans[i][1] = max(pre[i][1], sub[i][1]);
    }

    ranges::sort(ans, [](arr2 x, arr2 y){
        if (x[0] != y[0]) return x[0] < y[0];
        return x[1] < y[1];
    });

    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        // cout << ans[i][0] << ' ' << ans[i][1] << '\n';
        if (i == 0) {
            sum = ans[i][0] * (n * 2 - ans[i][1] + 1);
            continue;
        }

        sum += (ans[i][0] - ans[i - 1][0]) * (n * 2 - ans[i][1] + 1);
    }

    cout << sum << '\n';
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
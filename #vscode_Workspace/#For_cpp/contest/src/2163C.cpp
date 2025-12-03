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

    vector<int> ans(n * 2 + 1, INT_MAX);
    for (int i = 0; i < n; ++i) {
        int l = min(pre[i][0], sub[i][0]);
        int r = max(pre[i][1], sub[i][1]);

        ans[l] = min(ans[l], r);
    }

    ll sum = 0;
    if (ans[2 * n] != INT_MAX) {
        sum = 2 * n - ans[2 * n] + 1;
    }

    for (int i = n * 2 - 1; i >= 1; --i) {
        ans[i] = min(ans[i + 1], ans[i]);

        if (ans[i] != INT_MAX) {
            sum += 2 * n - ans[i] + 1;
        }
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
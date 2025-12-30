//https://codeforces.com/problemset/problem/2179/E

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
    ll n, x, y;
    cin >> n >> x >> y;
    string s; cin >> s;
    s = ' ' + s;
    vector<ll> p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    ll sump = 0;
    ll sum[2] = {0};
    ll left[2] = {0};
    ll cnt[2] = {0};
    ll sum2[2] = {0};
    
    for (int i = 1; i <= n; ++i) {
        int a = s[i] - '0';
        int b = a ^ 1;

        cnt[a]++;

        sum[a] += (p[i] / 2) + 1;
        sum[b] += (p[i] / 2);
        sum2[b] += (p[i] / 2);
        sump += p[i];

        if (p[i] % 2 == 0) {
            --sum[b];
            --sum2[b];
            ++left[a];
        }

        // cout << p[i] << ' ' << sum[0] << ' ' << sum[1] << '\n';
    } 

    if (x + y < sump || sum[0] > x + sum2[0] || sum[1] > y + sum2[1]) {
        cout << "NO\n";
        return;
    }

    x -= sum[0];
    y -= sum[1];

    if (cnt[0] && cnt[1]) {
        cout << "YES\n";
    }
    else {
        if (cnt[0] && x + left[0] < y) {
            cout << "NO\n";
        } else if (cnt[1] && y + left[1] < x) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    //  cout << x << ' ' <<  y << ' ' << left[0] << ' ' << left[1] << '\n';
} 

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "\n-----------\n";
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
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

void solve() {
    ll n, p;
    cin >> n >> p;

    auto mod = [&](int num) -> ll {
        num %= p;
        if (num < 0) num += p;
        return num;
    };

    arr3 ans = {}; //l r mx

    vector<ll> a(n), s(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i + 1] = a[i];
        if (i) s[i + 1] = mod(s[i] + s[i + 1]);
    }

    ll l, r, pos;
    set<ll> st = {0};
    map<int, int> mp;
    mp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        r = s[i];
        
        auto it = st.lower_bound(r - p + 1);
        if (it != st.end() && mod(r - *it) > ans[2]) {
            ans[2] = mod(r - *it);
            ans[0] = mp[*it];
            ans[1] = i - 1;

            // cout << i << " 1 " << *it << '\n';
        }

        it = st.lower_bound(r + 1);
        if (it != st.end() && mod(r - *it) > ans[2]) {
            ans[2] = mod(r - *it);
            ans[0] = mp[*it];
            ans[1] = i - 1;
            // cout << i << " 2 " << *it << '\n';
        }

        st.insert(s[i]);
        mp[s[i]] = i;
    }

    cout << ans[0] <<' ' << ans[1] << ' ' << ans[2] << '\n';
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

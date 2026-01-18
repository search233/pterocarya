//https://codeforces.com/problemset/problem/2176/C

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
    int n; cin >> n;
    vector<ll> odd;
    vector<ll> even;
    
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        if (num & 1) {
            odd.push_back(num);
        } else {
            even.push_back(num);
        }
    }

    ranges::sort(odd, greater());
    ranges::sort(even, greater());

    for (int i = 1; i < even.size(); ++i) {
        even[i] += even[i - 1];
        // cout << even[i] << " \n"[i == even.size() - 1];
    }

    vector<ll> ans(n + 1);
    if (odd.size() == 0) {
        for (int i = 1; i <= n; ++i) {
            cout << "0" << " \n"[i == n];
        }
        return;
    }

    ans[1] = odd.front();
    for (int i = 1; i <= even.size(); ++i) {
        // cout << ans[1] <<  "  " << even[i - 1] << " " ;
        ans[i + 1] = ans[1] + even[i - 1]; 
        // cout << ans[i + 1]<< " \n"[i == even.size()];
    }

    // if (even.size() == 0) even.push_back(0);

    for (int i = even.size() + 2; i <= n; ++i) {
        ans[i] = ans[i - 2];
    }

    if (odd.size() % 2 == 0) {
        ans.back() = 0;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
} 
 
int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        cout << "-----------\n";
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
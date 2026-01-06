//https://codeforces.com/problemset/problem/2157/D

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using arr2 = array<ll, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<ll> a;
    a.push_back(0);

    ll suml = 0, sumr = 0;

    for (int i = 1; i <= n; ++i) {
        ll num = 0;
        cin >> num;

        if (num <= l) {
            suml += l - num;
            sumr += r - num;
        } 
        else if (num >= r) {
            suml += num - l;
            sumr += num - r;
        }
        else {
            a.push_back(num);
        }

        // cout << a.size() << '\n';
    }

    
    ranges::sort(a);

    vector<ll> lfix, rfix;
    lfix.push_back(0);
    rfix.push_back(0);

    for (int i = 1; i < a.size(); ++i) {
        lfix.push_back(l - a[i] + lfix.back());
        rfix.push_back(r - a[i] + rfix.back());
    }

    

    ll ans = max(0ll, min(suml - lfix.back(), sumr - rfix.back()));
    // cout << ans << " ";
    
    for (int i = 1; i < a.size(); ++i) {
        ll templ = suml + lfix[i] - lfix.back() + lfix[i - 1];
        ll tempr = sumr + rfix[i] - rfix.back() + rfix[i - 1];

        ans = max(ans, min(templ, tempr));
        // cout << ans << ' ';

        ans = max(ans, min(templ + l - a[i], tempr + r - a[i]));
        // cout << ans << ' ';
    }

    cout << ans << '\n';
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
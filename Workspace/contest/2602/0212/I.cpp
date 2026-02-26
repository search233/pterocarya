//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<ll, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;

    vector<arr2> a(m + 1);

    for (int i = 0; i < m; ++i) {
        cin >> a[i][0] >> a[i][1]; //p f
    }
    
    
    auto ck = [&](int num) -> bool {
        vector<ll> sum(n + 5);

        auto add = [&](int l, int r, ll val) -> void {
            sum[l] += val;
            sum[r + 1] -= val; 
        };

        for (int i = 0; i < num; ++i) {
            auto [p, f] = a[i];
            ll l = p - f + 1;

            if (l > 0) {
                add(p - f + 1, p, 1);
            }
            else {
                add(1, 1, 1 - p + f);
                if (p > 1) add(2, p, 1);
            }
            
            add(p + 1, min(p + f, n + 1), -1);

            // for (int i = 1; i <= n; ++i) {
            //     cout << sum[i] << " \n"[i == n];
            // }
        }

        for (int i = 1; i <= n; ++i) {
            sum[i] += sum[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            sum[i] += sum[i - 1];
            if (sum[i] > h) {
                return true;
            }
        }
        return false;
    };

    if (!ck(m)) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    int l = 1, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ck(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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

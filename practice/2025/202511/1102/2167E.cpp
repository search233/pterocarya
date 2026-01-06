//https://codeforces.com/problemset/problem/2167/E

#include <bits/stdc++.h>
#define int long long

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
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (auto& i : a) cin >> i;

    ranges::sort(a);

    auto cmp = [](arr3 x, arr3 y) -> bool {
        return x[2] < y[2];
    };

    priority_queue<arr3, vector<arr3>, decltype(cmp)> pq(cmp);

    pq.push({0, a.front(), a.front() + 1});
    pq.push({x, a.back(), x - a.back() + 1});

    for (int i=0 ; i<a.size() - 1 ; ++i) {
        int len = a[i + 1] - a[i] + 1;

        // cout << len << '\n';
        if (len & 1) {
            pq.push({len / 2 + a[i], a[i], len / 2 + 1});
            pq.push({len / 2 + a[i] + 1, a[i + 1], len / 2});
        } 
        else {
            pq.push({len / 2 + a[i] - 1, a[i], len / 2});
            pq.push({len / 2 + a[i], a[i + 1], len / 2});
        }
    }

    set<int> ans;
    for (int i=0 ; i<k ; ++i) {
        auto [a1, a2, w] = pq.top();
        pq.pop();

       

        if (!ans.count(a1)) {
            // cout << '\n' << a1 << ' ' << a2 << ' ' << w << '\n';
            cout << a1 << ' ';
            ans.insert(a1);
        }else --i;

        --w;
        
        if (w > 0) {
            if (a1 < a2) pq.push({a1 + 1, a2, w});
            else pq.push({a1 - 1, a2, w});
        }
    }

    cout << '\n';
} 

signed main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

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
//https://ac.nowcoder.com/acm/contest/108306/L

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

void solve() {
    int n, k;
    cin >> n >> k;

    int mx = 0;
    vector<int> a(n);

    for (auto& x : a) 
    cin >> x, mx = max(mx, x);

    queue<int> qu;
    for (int i=1 ; i<n ; ++i) qu.push(i);

    vector<int> res(n, 0);
    int idx = 0, cnt = 0;

    int lim = min(k, n * 4);

    while (lim--) {
        --k;
        ++cnt;
        
        int ftidx = qu.front();
        qu.pop();

        ++res[ftidx];
        ++res[idx];

        if (a[idx] <= a[ftidx] || cnt == n) {
            qu.push(idx); 
            idx = ftidx;
            cnt = 1;
        } else qu.push(ftidx);
    }

    while(k) {
        int ftidx = qu.front();
        if (a[ftidx] == mx) break;
        
        --k;
        ++cnt;
        qu.pop();

        ++res[ftidx];
        ++res[idx];

        if (a[idx] < a[ftidx] || cnt == n) {
            qu.push(idx); 
            idx = ftidx;
            cnt = 1;
        } else qu.push(ftidx);
    }

    int sum = k / ((n - 1) * 2);
    k -= sum * (n - 1) * 2;

    for (int i=0 ; i<n ; ++i) {
        if (a[i] != mx && i != idx) res[i] += sum * 2;
        else res[i] += sum * n;
    }

    while(k--) {
        ++cnt;

        int ftidx = qu.front();
        qu.pop();

        ++res[ftidx];
        ++res[idx];

        if (a[idx] < a[ftidx] || cnt == n) {
            qu.push(idx); 
            idx = ftidx;
            cnt = 1;
        } else qu.push(ftidx);
    }

    for (int i=0 ; i<n ; ++i)
    cout << res[i] << (i < n-1 ? ' ' : '\n');
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*

        int ftidx = qu.front();
        qu.pop();

        ++res[ftidx];
        ++res[idx];
        ++cnt;

        if (a[idx] < a[ftidx] || cnt == n) {
            qu.push(idx); 
            idx = ftidx;
            cnt = 1;
        } else qu.push(ftidx);

        
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
│ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

*/
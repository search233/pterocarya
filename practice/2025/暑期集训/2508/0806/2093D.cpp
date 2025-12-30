//https://codeforces.com/problemset/problem/2093/D

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

ll getd(ll x, ll y, ll n) {

    if (n == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 1 && y == 2) return 4;
        if (x == 2 && y == 1) return 3;
        if (x == 2 && y == 2) return 2;
    }

    int mid = (1LL << n) / 2;
    if (x <= mid && y <= mid) return getd(x, y, n - 1);
    else if (x <= mid && y > mid) return getd(x, y - mid, n - 1) + (1LL << (2*n-2))*3;
    else if (x > mid && y <= mid) return getd(x - mid, y, n - 1) + (1LL << (2*n-2))*2;
    //else if (x >= mid && y >= mid) 
    return getd(x - mid, y - mid, n - 1) + (1LL << (2*n-2));
}

void solve() {
    ll n, q;
    cin >> n >> q;
    
    for (int i=0 ; i<q ; ++i) {
        string s;
        cin >> s;

        if (s == "<-") {
            // cout << "fuck   ";
            ll num; cin >> num;

            auto cal = [=](ll num) -> void {
                ll tmp = 1;

                while (num > (1ll << (tmp * 2))) {
                    ++tmp;
                }

                ll xu = 1, xd = (1ll << tmp);
                ll yl = 1, yr = (1ll << tmp);

                vector<ll> fac;
                do {
                    fac.push_back(4 - num % 4);
                    if (num % 4) num = num/4 + 1;
                    else num /= 4;
                }while (num != 1);

                for (int i=fac.size() - 1 ; i>=0 ; --i) {
                    ll dx = (xd - xu + 1ll) >> 1ll;
                    ll dy = (yr - yl + 1ll) >> 1ll;

                    if (fac[i] == 1 ) xu += dx, yr -= dy;
                    else if (fac[i] == 2) xu += dx, yl += dy;
                    else if (fac[i] == 3) xd -= dx, yr -= dy;
                    else if (fac[i] == 4) xd -= dx, yl += dy;
                }

                cout << xd << ' ' << yl << '\n';
            };

            cal(num);
        } else {
            ll x, y;
            cin >> x >> y;

            // cout << "fucking output" << '\n';
            cout << getd(x, y, n) << '\n';
        }
    }
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
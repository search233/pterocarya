//https://vjudge.net/problem/QOJ-10544

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const int INF = INT_MAX >> 1;
const double PI = acos(-1.0);


void solve() {
    int n, L;
    cin >> L >> n;

    vector<int> p(n);
    int l = 1, r = 0, mid;

    for (int i=0 ; i<n ; ++i) {
        cin >> p[i];
        if (i) r = max(p[i] - p[i - 1], r);
    }

    auto check = [=](int mid) -> int {

        // cout << "\n===============\n" << mid << '\n';
        vector<int> Rpos(n, L), Lpos(n, 0);

        for (int i=0 ; i<n - 1 ; ++i) {
            int dis = mid - (p[i] - Lpos[i]);
            if (dis < 0) Lpos[i + 1] = -INF;
            else Lpos[i + 1] = min(Lpos[i] + dis, p[i + 1]);
        }

        for (int i=n-1 ; i>0 ; --i) {
            int dis = mid - (Rpos[i] - p[i]);
            if (dis < 0) Rpos[i - 1] = INF;
            else Rpos[i - 1] = max(Rpos[i] - dis, p[i - 1]);
        }

        // for (auto& i : Rpos) cout << i << ' ';
        // cout << '\n';

        // for (auto& i : Lpos) cout << i << ' ';
        // cout << '\n';

        for (int i=0 ; i<n ; ++i) {
            if (Lpos[i] == -INF || Rpos[i] == INF) continue;
            int ldis = p[i] - Lpos[i];
            int rdis = Rpos[i] - p[i];
            if (ldis + rdis + min(ldis, rdis) <= mid) {
                // cout << i  << "fking out here\n";
                return 1;
            }
        }



        return 0;
    };

    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            // cout << "fuck r = " << r << "\n";
        } else {
            l = mid + 1;
            // cout << "fuck l = " << l << "\n";
        }
    }

    cout << l << "\n";
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    // cin >> _T;

    while (_T--) {
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
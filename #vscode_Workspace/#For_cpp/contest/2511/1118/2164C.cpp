//https://codeforces.com/problemset/problem/2164/C

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

    int n, m;
    cin >> n >> m;

    map<int, int> a;
    for (int i=0 ; i<n ; ++i) {
        int tmp; cin >> tmp;
        ++a[tmp];
    }

    vector<int> b(m);
    map<int, int> b2;
    vector<arr2> b1;

    for (int i=0 ; i<m ; ++i) {
        cin >> b[i];
    }

    for (int i=0 ; i<m ; ++i) {
        int c; cin >> c;
        if (c) b1.push_back({b[i], c});
        else   ++b2[b[i]];
    }

    sort(b1.begin(), b1.end());

    int ans = 0;
    if (a.empty()) {
        cout << ans << '\n';
        return;
    }

    for (int i=0 ; i<b1.size() ; ++i) {        
        auto it = a.lower_bound(b1[i][0]);
        
        if (it == a.end()) {
            break;
        }
        else {
            auto& [num, times] = *it;
            ++ans;

            if (num < b1[i][1]) {
                --times;
               if (times == 0) a.erase(num);

               ++a[b1[i][1]];
            }
        }
    }

    for (auto& [anum, atimes] : a) {
        for (int i=0 ; i<atimes ; ++i) {
            auto it = b2.upper_bound(anum);

            if (it == b2.begin()) break;
        
            --it;
            auto& [num, times] = *it;

            ++ans;
            --times;
            if (times == 0) b2.erase(num);
        }
    }

    cout << ans << '\n';
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
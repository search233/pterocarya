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
    scanf("%d %d", &n, &m);

    multiset<int> a;
    for (int i=0 ; i<n ; ++i) {
        int tmp; 
        scanf("%d", &tmp);
        a.insert(tmp);
    }

    vector<int> b(m);
    multiset<int> b2;
    vector<arr2> b1;
    for (int i=0 ; i<m ; ++i) {
        cin >> b[i];
    }

    for (int i=0 ; i<m ; ++i) {
        int c; cin >> c;
        if (c) b1.push_back({b[i], c});
        else   b2.insert(b[i]);
    }

    sort(b1.begin(), b1.end());

    int ans = 0;
    if (a.empty()) {
        cout << ans << '\n';
        return;
    }

    for (int i=0 ; i<b1.size() ; ++i) {
        int x = b1[i][0];
        
        auto it = lower_bound(a.begin(), a.end(), x);
        
        if (it == a.end()) {
            break;
        }
        else {
            ++ans;

            if (*it < b1[i][1]) {
                a.erase(it);
                a.insert(b1[i][1]);
            }
        }
    }

    for (auto& i : a) {
        auto it = upper_bound(b2.begin(), b2.end(), i);

        if (it == b2.begin()) continue;
        
        --it;
        ++ans;
        b2.erase(it);
    }

    cout << ans << '\n';    
} 

int main() {
    
    // __BUFF__

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
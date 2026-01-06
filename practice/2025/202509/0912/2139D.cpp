//https://codeforces.com/problemset/problem/2139/D

#include <bits/stdc++.h>

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
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto& i : a) cin >> i;

    stack<int> st;
    vector<int> ans(n, -1);

    vector<int> lnum(n, -1);
    for (int i=0 ; i<n ; ++i) {
        while (!st.empty() && a[i] > a[st.top()]) st.pop();
        
        if (!st.empty()) {
            lnum[i] = st.top();           
        }

        st.push(i); 
    }
    while (!st.empty()) st.pop();
    
    vector<int> rnum(n, -1);
    for (int i=n-1 ; i>=0 ; --i) {
        while (!st.empty() && a[i] < a[st.top()]) st.pop();
        
        if (!st.empty()) {
            rnum[i] = st.top();
            if (lnum[i] != -1) {
                if (ans[lnum[i]] == -1) ans[lnum[i]] = rnum[i];
                else ans[lnum[i]] = min(rnum[i], ans[lnum[i]]);
            }
        }

        st.push(i); 
    }

    // for (int i=n-2 ; i>=0 ; --i) {
    //     if (ans[i + 1] != -1) {
    //         if (ans[i] == -1) ans[i] = ans[i + 1];
    //         else ans[i] = min(ans[i], ans[i + 1]);
    //     }
    // }

    int tag = -1;
    for (int i=n-1 ; i>=0 ; --i) {
        if (ans[i] != -1) {
            if (tag == -1) tag = ans[i];
            else ans[i] = tag = min(ans[i], tag);
        }
        else if (tag != -1) ans[i] = tag;
    }


    // for (int i=0 ; i<n ; ++i) cout << ans[i]  << '\n'; 

    for (int i=0 ; i<q ; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if (r >= ans[l] && ans[l] != -1) cout << "NO\n";
        else cout << "YES\n";

        // cout << ans[l] << '\n';
    }
    // cout << '\n';
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------" << '\n';
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
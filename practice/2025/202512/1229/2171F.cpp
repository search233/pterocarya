//https://codeforces.com/problemset/problem/2171/F

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
    int n; cin >> n;
    vector<int> a(n);

    for (auto& i : a) cin >> i;

    stack<arr2> st;
    vector<vector<int>> e(n + 1);

    for (int i = 0; i < n; ++i) {
        if (st.empty() || a[i] < st.top()[0]) {
            st.push({a[i], a[i]});
            continue;
        }

        arr2 top = st.top();
        top[1] = max(top[1], a[i]);

        e[top[0]].push_back(a[i]);
        e[a[i]].push_back(top[0]);

        st.pop();

        while (!st.empty() && top[1] > st.top()[0]) {

            e[st.top()[0]].push_back(top[1]);
            e[top[1]].push_back(st.top()[0]);

            st.top()[0] = min(st.top()[0], top[0]);
            st.top()[1] = max(st.top()[1], top[1]);
            top = st.top();
            st.pop();
        }
        st.push(top);
    }

    auto dfs = [&](auto& dfs, int u, int fa) -> void {
        // cout << "1111\n";
        if (fa != -1) {
            cout << fa << ' ' << u << '\n';
        }

        for (auto& v : e[u]) {
            if (v != fa) {
                dfs(dfs, v, u);
            }
        }
    };

    if (st.size() == 1) {
        cout << "Yes\n";
        dfs(dfs, 1, -1);
    } else {
        cout << "No\n";
    }
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
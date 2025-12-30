//https://codeforces.com/problemset/problem/2179/F

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void first() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n + 1);
    vector<char> s(n + 1); 

    int u, v;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto ch = [&](int d) -> char {
        char ch;
        if (d % 3 == 0) ch = 'r';
        if (d % 3 == 1) ch = 'g';
        if (d % 3 == 2) ch = 'b';

        return ch;
    };

    queue<arr2> qu;
    qu.push({1, 0});
    vector<int> vis(n + 1);

    while (!qu.empty()) {
        auto [u, d] = qu.front();
        qu.pop();
        vis[u] = 1;
        s[u] = ch(d);

        for (auto& v : e[u]) {
            if (vis[v]) continue;
            else {
                // cout << v << ' ';
                qu.push({v, d + 1});
            }
        }
        // cout << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        cout << s[i];
    }
    cout << '\n';
}

void second() {
    int q; cin >> q;

    for (int i = 0; i < q; ++i) {
        int len; cin >> len;
        string s; cin >> s;
        int cnt[3] = {0};
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'r') ++cnt[0];
            else if (s[i] == 'g') ++cnt[1];
            else ++cnt[2];
        }

        char c;

        if (cnt[0] && cnt[2]) {
            c = 'r';
        } else if (cnt[0] && cnt[1]) {
            c = 'g';
        } else if (cnt[1] && cnt[2]) {
            c = 'b';
        } else {
            if (cnt[0]) {
                c = 'r';
            } else if (cnt[1]) {
                c = 'g';
            } else {
                c = 'b';
            }
        }
            
        for (int i = 0; i < len; ++i) {
            if (s[i] == c)  {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
}


int main() {
    
    __BUFF__

    int _ = 1;
    string s;
    cin >> s;

    if (s == "first") {        
        cin >> _;
        while (_--) {
            first();
            // cout << "-----------\n";
        }
    }
    else {
        cin >> _;
        while (_--) {
            second();
            // cout << "-----------\n";
        }
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
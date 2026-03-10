//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

struct LB { // Linear Basis
    using i64 = long long;
    static const int BASE = 60;
    i64 d[BASE]; 
    int idx[BASE];
    i64 path[BASE];
     
    LB() { 
        memset(d, 0, sizeof d);
        memset(idx, 0, sizeof idx);
        memset(path, 0, sizeof path);
    }

    bool insert(i64 val, int id) {
        i64 res = 0;
        for (int i = BASE - 1; i >= 0; i--) {
            if (val & (1ll << i)) {
                if (!d[i]) {
                    d[i] = val;
                    idx[i] = id;
                    path[i] = res;
                    return true;
                }
                val ^= d[i];
                res |= (1LL << i);
            }
        }
        return false;
    }

    // 返回：用哪些“基向量”表示了 val（用 bitmask 表示）
    // 如果不能表示，返回 -1
    i64 QueryMask(i64 x) {
        i64 res = 0;
        for (int i = BASE - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!d[i]) return -1;
                x ^= d[i];
                res |= (1LL << i);    
            }
        }
        return res;
    }

    // 封装好的接口：
    // 如果 val 可表示，返回选中的“原始下标集合”
    // 如果不可表示，返回空 vector
    vector<int> get_path(i64 val, int n) {
        i64 mask = QueryMask(val);
        if (mask == -1) return {}; // 表示不了

        vector<int> vis(n + 1, 0);

        // 展开基向量到原始下标
        for (int i = 0; i < BASE; i++) {
            if (mask >> i & 1) {
                int id = idx[i];
                vis[id] ^= 1;
                mask ^= path[i];
            }
        }

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) res.push_back(i);
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s ^= a[i];
    }

    LB lb;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        lb.insert(b[i] ^ a[i], i + 1);

    }

    if (s == 0) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    else {
        auto ans = lb.get_path(s, n);
        if (ans.empty()) {
            cout << "-1\n";
        }
        else {
            int p = 0;
            for (int i = 0; i < n; ++i) {
                if (p < ans.size() && ans[p] == i + 1) {
                    cout << b[ans[p] - 1];
                    ++p;
                }
                else {
                    cout << a[i];
                }
                cout << " ";
            }
            // for (int i = 0; i < ans.size(); ++i) {
            //     cout << ans[i] << " ";
            // }
            cout << '\n';
        }
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
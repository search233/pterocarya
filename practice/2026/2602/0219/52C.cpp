//https://codeforces.com/problemset/problem/52/C

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

vector<ll> read() {
    string s;
    getline(cin >> ws, s);

    vector<ll> res;

    ll num = 0;
    int sign = 1;
    bool in = false;   // 当前是否正在读数字

    for (char c : s) {
        if (c == '-') {
            sign = -1;
            in = true;
            num = 0;
        }
        else if (isdigit(c)) {
            num = num * 10 + (c - '0');
            in = true;
        }
        else {
            if (in) {
                res.push_back(sign * num);
                num = 0;
                sign = 1;
                in = false;
            }
        }
    }

    // 行末数字
    if (in)
        res.push_back(sign * num);

    return res;
}


struct SegTree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)

    struct Node {
        int l, r;      // 当前节点表示的区间 [l, r]

        // ====== 要维护的信息 ======
        ll mn;
        ll add;
        // ==================================

        Node(): l(0), r(0), mn(0), add(0) {}
    };

    int n;
    vector<Node> tree;

    SegTree(const vector<ll>& vec) {
        int len = vec.size() - 1;
        tree.assign(len << 2, Node());

        auto build = [&](auto& build, int rt, int l, int r) -> void {
            tree[rt].l = l;
            tree[rt].r = r;
            
            if (l == r) {
                // 初始化
                tree[rt].mn = vec[l];
                return;
            }

            int mid = l + r >> 1;
            build(build, ls, l, mid);
            build(build, rs, mid + 1, r);
            push_up(rt);
        };

        build(build, 1, 1, len);
    } 

    // 向上合并
    void push_up(int rt) {
        // ====== 合并左右区间信息 ======
        tree[rt].mn = min(tree[ls].mn, tree[rs].mn);
        // ==========================================
    }

    // 下推懒标记：把当前节点的 lazy 影响传给子节点
    void push_down(int rt) {
        if (tree[rt].add != 0 && tree[rt].l != tree[rt].r) {
            // ====== lazy 下传 ======
            // 区间加：
            tree[ls].mn += tree[rt].add;
            tree[ls].add += tree[rt].add;

            tree[rs].mn += tree[rt].add;
            tree[rs].add += tree[rt].add;
            // ====================================

            tree[rt].add = 0; // 清空当前节点懒标记
        }
    }

    // 区间修改：[L, R] 对区间做某种操作
    void modify(int L, int R, ll v, int rt = 1) {
        if (L <= tree[rt].l && tree[rt].r <= R) {
            // ====== 整段覆盖时更新, 打标记 ======
            tree[rt].mn += v;
            tree[rt].add += v;
            // =========================================
            return;
        }

        push_down(rt);

        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if (L <= mid) modify(L, R, v, ls);
        if (R >  mid) modify(L, R, v, rs);

        push_up(rt);
    }

    // 区间查询：[L, R] 查询区间信息
    ll query(int l, int r, int rt = 1) {
        if (l <= tree[rt].l && tree[rt].r <= r) {
            return tree[rt].mn;
        }

        push_down(rt);
        int mid = tree[rt].l + tree[rt].r >> 1;

        if (r <= mid) return query(l, r, ls);
        if (l > mid) return query(l, r, rs);

        return min(query(l, r, ls), query(l, r, rs));
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    int m; cin >> m;
    SegTree st(a);

    while (m--) {
        vector<ll> vec = read();
        ll lf = vec[0] + 1;
        ll rg = vec[1] + 1;

        if (vec.size() == 2) {
            // cout << lf << ' ' << rg << '\n';
            if (lf > rg) {
                cout << min(st.query(1, rg), st.query(lf, n)) << '\n';
            }
            else {
                cout << st.query(lf, rg) << '\n';
            }
        }
        else if (vec.size() == 3) {
            ll v = vec[2];
            // cout << v << '\n';
            if (lf > rg) {
                st.modify(1, rg, v);
                st.modify(lf, n, v);
            } 
            else st.modify(lf, rg, v);
        }
    }
} 

int main() {
    
    __BUFF__

    int _ = 1;
    // cin >> _;

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

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

struct SegTree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)

    struct Node {
        int l, r;      // 当前节点表示的区间 [l, r]

        // ====== 要维护的信息 ======
        // int val;       
        // int lazy;
        int f;
        int cost;
        // ==================================

        Node(): l(0), r(0) ,f(0), cost(1) {}
    };

    int n;
    vector<Node> tree;

    SegTree(const vector<int>& vec) {
        int len = vec.size() - 1;
        tree.assign(len << 2, Node());

        auto build = [&](auto& build, int rt, int l, int r) -> void {
            tree[rt].l = l;
            tree[rt].r = r;
            
            if (l == r) {
                // 初始化
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
        if (tree[rt].f) {
            tree[rt].cost = tree[ls].cost + tree[rs].cost;
        }
        // tree[rt].val = tree[ls].val + tree[rs].val;
        // ==========================================
    }

    // 下推懒标记：把当前节点的 lazy 影响传给子节点
    // void push_down(int rt) {
    //     if (tree[rt].lazy != 0 && tree[rt].l != tree[rt].r) {
    //         // ====== lazy 下传 ======
    //         // 区间加：
    //         // tree[ls].lazy += tree[rt].lazy;
    //         // tree[rs].lazy += tree[rt].lazy;
    //         // ====================================

    //         tree[rt].lazy = 0; // 清空当前节点懒标记
    //     }
    // }

    // 区间修改：[L, R] 对区间做某种操作
    void modify(int L, int R, int rt = 1) {
        if (L <= tree[rt].l && tree[rt].r <= R) {
            // ====== 整段覆盖时更新, 打标记 ======
            tree[rt].f = 1;
            tree[rt].cost = tree[ls].cost + tree[rs].cost;
            // =========================================
            return;
        }

        // push_down(rt);

        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if (L <= mid) modify(L, R, ls);
        if (R >  mid) modify(L, R, rs);

        push_up(rt);
    }

    // 区间查询：[L, R] 查询区间信息
    int query(int l, int r, int rt = 1) {
        if (l <= tree[rt].l && tree[rt].r <= r) {
            return tree[rt].cost;
        }

        // push_down(rt);
        int mid = tree[rt].l + tree[rt].r >> 1;

        int res = (!tree[rt].f);
        if (r <= mid) return res + query(l, r, ls);
        if (l > mid) return res + query(l, r, rs);

        return res + query(l, r, ls) + query(l, r, rs);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    SegTree st(a);
    int op, l, r;

    for (int i = 0; i < n; ++i) {
        cin >> op >> l >> r;

        if (op == 1) {
            st.modify(l, r);
        }
        else {
            cout << st.query(l, r) << '\n';
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

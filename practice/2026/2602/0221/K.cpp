//https://atcoder.jp/contests/practice2/tasks/practice2_k


#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);
const ll MOD = 998244353;

ll mod(ll num) {
    num %= MOD;
    if (num < 0) num += MOD;
    return num;
}

struct SegTree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)

    struct Node {
        int l, r;      // 当前节点表示的区间 [l, r]

        // ====== 要维护的信息 ======
        ll sum;       
        ll mul;     
        ll add;
        // ==================================

        Node(): l(0), r(0), sum(0), mul(1), add(0) {}
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
                tree[rt].sum = vec[l];
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
        tree[rt].sum = mod(tree[ls].sum + tree[rs].sum);
        // ==========================================
    }

    // 下推懒标记：把当前节点的 lazy 影响传给子节点
    void push_down(int rt) {
        if ((tree[rt].add != 0 || tree[rt].mul != 1 ) && tree[rt].l != tree[rt].r) {
            // ====== lazy 下传 ======
            // 区间加：
            ll len = tree[rs].r - tree[rs].l + 1;
            tree[rs].sum = mod(mod(tree[rs].sum * tree[rt].mul) + mod(tree[rt].add * len));
            tree[rs].add = mod(mod(tree[rs].add * tree[rt].mul) + tree[rt].add);
            tree[rs].mul = mod(tree[rs].mul * tree[rt].mul);
            
            len = tree[ls].r - tree[ls].l + 1;
            tree[ls].sum = mod(mod(tree[ls].sum * tree[rt].mul) + mod(tree[rt].add * len));
            tree[ls].add = mod(mod(tree[ls].add * tree[rt].mul) + tree[rt].add);
            tree[ls].mul = mod(tree[ls].mul * tree[rt].mul);
            // ====================================

            tree[rt].add = 0; // 清空当前节点懒标记
            tree[rt].mul = 1;
        }
    }

    // 区间修改：[L, R] 对区间做某种操作
    void modify(int L, int R, ll b, ll c, int rt = 1) {
        if (L <= tree[rt].l && tree[rt].r <= R) {
            // ====== 整段覆盖时更新, 打标记 ======
            ll len = tree[rt].r - tree[rt].l + 1;
            tree[rt].sum = mod(mod(tree[rt].sum * b) + mod(c * len));
            tree[rt].add = mod(mod(tree[rt].add * b) + c);
            tree[rt].mul = mod(tree[rt].mul * b);
            // =========================================
            return;
        }

        push_down(rt);

        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if (L <= mid) modify(L, R, b, c, ls);
        if (R >  mid) modify(L, R, b, c, rs);

        push_up(rt);
    }

    // 区间查询：[L, R] 查询区间信息
    ll query(int l, int r, int rt = 1) {
        if (l <= tree[rt].l && tree[rt].r <= r) {
            return tree[rt].sum;
        }

        push_down(rt);
        int mid = tree[rt].l + tree[rt].r >> 1;

        if (r <= mid) return query(l, r, ls);
        if (l > mid) return query(l, r, rs);

        return mod(query(l, r, ls) + query(l, r, rs));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegTree st(a);

    ll op, l, r, b, c;
    for (int i = 0; i < q; ++i) {
        cin >> op;
        if (op == 0) {
            cin >> l >> r >> b >> c;
            st.modify(l + 1, r, b, c);
        }
        else {
            cin >> l >> r;
            cout << st.query(l + 1, r) << '\n';
            // for (int i = 1; i <= n; ++i) {
            //     cout << st.query(i, i) << ' ';
            // }
            // cout << '\n';
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
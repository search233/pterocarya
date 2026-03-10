//https://codeforces.com/problemset/problem/446/C

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<ll, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 9;

ll Fib[300010] = {0};

arr2 fib(int k) {
    return arr2{Fib[k], Fib[k + 1]};
}

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
        ll g1, g2;        
        // ==================================

        Node(): l(0), r(0), sum(0), g1(0), g2(0) {}
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

    void ap(int rt, ll g1, ll g2) {
        ll len = tree[rt].r - tree[rt].l + 1;
        auto [f1, f2] = fib(len);

        tree[rt].sum = mod(mod(mod(g1 * f1) + mod(g2 * (f2 - 1))) + tree[rt].sum);

        tree[rt].g1 = mod(g1 + tree[rt].g1);
        tree[rt].g2 = mod(g2 + tree[rt].g2);
    }

    // 下推懒标记：把当前节点的 lazy 影响传给子节点
    void push_down(int rt) {
        if ((tree[rt].g1 != 0  || tree[rt].g2 != 0) && tree[rt].l != tree[rt].r) {
            // cout << "push_down : " << rt << ' ' << tree[rt].g1 << ' ' << tree[rt].g2 << '\n';
            // ====== lazy 下传 ======
            ap(ls, tree[rt].g1, tree[rt].g2);
            
            int mid = (tree[rt].l + tree[rt].r) >> 1;
            auto [gg1, gg2] = fib(mid - tree[rt].l);
            gg1 = mod(mod(tree[rt].g1 * gg1) + mod(tree[rt].g2 * gg2));
            gg2 = mod(mod(tree[rt].g1 * gg2) + mod(tree[rt].g2 * fib(mid - tree[rt].l + 2)[0]));
            ap(rs, gg1, gg2);
            // ====================================

            tree[rt].g1 = 0; 
            tree[rt].g2 = 0; // 清空当前节点懒标记
        }
    }

    // 区间修改：[L, R] 对区间做某种操作
    void modify(int L, int R, int rt = 1) {
        // cout << L << ' ' << R << ' ' << g1 << ' ' << g2 << ' ' << rt << '\n';

        int mid = (tree[rt].l + tree[rt].r) >> 1;
        
        if (L <= tree[rt].l && tree[rt].r <= R) {
            // ====== 整段覆盖时更新, 打标记 ======
            auto [g1, g2] = fib(tree[rt].l - L + 1);
            ap(rt, g1, g2);
            // =========================================
            return;
        }

        push_down(rt);

        
        if (L <= mid) modify(L, R, ls);
        // cout << gg1 << ' ' << gg2 << '\n';
        if (R >  mid) modify(L, R, rs);

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
    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    Fib[0] = 0;
    Fib[1] = 1;
    for (int i = 2; i <= n + 5; ++i) {
        Fib[i] = mod(Fib[i - 1] + Fib[i - 2]);
    }

    SegTree st(a);
    int op, l, r;

    for (int i = 0; i < m; ++i) {
        cin >> op >> l >> r;
        if (op == 1) {
            st.modify(l, r);
        }
        else {
            cout << st.query(l, r) << '\n';
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

 arr2 fib(ll n) {
    if (n == 0) return {0, 1};

    auto [a, b] = fib(n >> 1); // F(k), F(k+1)

    ll c = mod(mod(mod(2 * b) - a) * a);        // F(2k)
    ll d = mod(mod(a * a) + mod(b * b));          // F(2k+1)

    if (n & 1) 
        return {d, mod(c + d)};         // F(2k+1), F(2k+2)
    else
        return {c, d};
}
*/

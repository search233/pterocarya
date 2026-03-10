//https://www.luogu.com.cn/problem/P1438

#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

#define int long long
using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

struct SegTree{
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)

    struct node {
        int l, r;
        int sum;
        int d, k;
        node(): l(0), r(0), sum(0) ,d(0), k(0){}
    };

    int len;
    vector<node> tree;

    SegTree(const vector<int>& vec) {
        len = vec.size() - 1;
        tree.assign((len << 2) + 5, node());

        auto build = [&](auto& build, int rt, int l, int r) -> void {
            tree[rt].l = l;
            tree[rt].r = r;
            
            if (l == r) {
                tree[rt].sum = vec[l];
                return;
            }

            int mid = (l + r) >> 1;
            build(build, ls, l, mid);
            build(build, rs, mid + 1, r);
            push_up(rt);
        };

        build(build, 1, 1, len);
    }   

    void push_up(int rt) {
        tree[rt].sum = tree[ls].sum+ tree[rs].sum;
    }

    void push_down(int rt) {
        if (tree[rt].l == tree[rt].r) return;
        if (tree[rt].d == 0 && tree[rt].k == 0) return;

        //ls
        int a1 = tree[rt].k;
        int d = tree[rt].d;
        int n = tree[ls].r - tree[ls].l + 1;
        tree[ls].sum += n * a1 + n * (n - 1) * d / 2;
        tree[ls].k += a1;
        tree[ls].d += tree[rt].d;

        a1 = tree[rt].k + (tree[rs].l - tree[rt].l) * d;
        n = tree[rs].r - tree[rs].l + 1;
        tree[rs].sum += n * a1 + n * (n - 1) * d / 2;
        tree[rs].k += a1;
        tree[rs].d += tree[rt].d;

        tree[rt].k = 0;
        tree[rt].d = 0;
    }

    void add_modify(int l, int r, int k, int d, int rt = 1) {
        if (tree[rt].l >= l && tree[rt].r <= r) {
            int a1 = k + (tree[rt].l - l) * d;
            int n = tree[rt].r - tree[rt].l + 1;
            tree[rt].sum += n * a1 + n * (n - 1) * d / 2;
            tree[rt].k += a1;
            tree[rt].d += d;
            return;
        }

        push_down(rt);

        int mid = (tree[rt].l + tree[rt].r) >> 1;       

        if (l <= mid) {
            add_modify(l, r, k, d, ls);
        }

        if (r >= mid + 1) {
            add_modify(l, r, k, d, rs);
        }

        push_up(rt);
    }

    int query(int l, int r, int rt = 1) {
        if (l <= tree[rt].l && tree[rt].r <= r) {
            return tree[rt].sum;
        }

        push_down(rt);
        int mid = (tree[rt].l + tree[rt].r) >> 1;

        if (r <= mid) return query(l, r, ls);
        if (l > mid) return query(l, r, rs);

        return query(l, r, ls) + query(l, r, rs);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegTree st(a);

    for (int i = 0; i < m; ++i) {
        int tag; cin >> tag;
        if (tag == 1) {
            int l, r, k, d;
            cin >> l >> r >> k >> d;

            st.add_modify(l, r, k, d);
        }
        else {
            int p; cin >> p;
            cout << st.query(p, p) << '\n';
        }
    }
} 

signed main() {
    
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
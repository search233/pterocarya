//https://www.luogu.com.cn/problem/P3373

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

int m;

inline int mod(int num) {
    num %= m;
    if (num < 0) num += m;
    return num;
}

struct SegTree{
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)

    struct Node{
        int l, r;
        int sum;
        int add;
        int mul;

        Node(): l(0), r(0), sum(0), add(0), mul(1){}
    };

    void build(int rt, int l, int r) {
        tr[rt].l = l;
        tr[rt].r = r;

        if (l == r) return;
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
    }


    int n;
    vector<Node> tr;

    SegTree(int n) {
        this->n = n + 1;
        tr.assign(n << 2, Node());
        build(1, 1, n);
    }

    void push_up(int rt) {
        tr[rt].sum = mod(tr[ls].sum + tr[rs].sum);
    }

    void push_down(int rt) {
        if (tr[rt].l == tr[rt].r) return;
        if (tr[rt].add == 0 && tr[rt].mul == 1) return;

        int lenl = tr[ls].r - tr[ls].l + 1;
        int lenr = tr[rs].r - tr[rs].l + 1;

        int Add = tr[rt].add;
        int Mul = tr[rt].mul;

        tr[ls].sum = mod(tr[ls].sum * Mul + lenl * Add);
        tr[ls].mul = mod(tr[ls].mul * Mul);
        tr[ls].add = mod(mod(tr[ls].add * Mul) + Add);

        tr[rs].sum = mod(tr[rs].sum * Mul + lenr * Add);
        tr[rs].mul = mod(tr[rs].mul * Mul);
        tr[rs].add = mod(mod(tr[rs].add * Mul) + Add);
        
        tr[rt].add = 0;
        tr[rt].mul = 1;
    }

    void add_modify(int l, int r, int val, int rt = 1) {
        if (l <= tr[rt].l && tr[rt].r <= r) {
            tr[rt].sum = mod(tr[rt].sum + mod(val * (tr[rt].r - tr[rt].l + 1)));
            tr[rt].add = mod(tr[rt].add + val);
            return;
        }

        push_down(rt);
        int mid =  (tr[rt].l + tr[rt].r) >> 1;

        if (l <= mid) {
            add_modify(l, r, val, ls);
        }

        if (mid + 1 <= r) {
            add_modify(l, r, val, rs);
        }

        push_up(rt);
    }

    void mul_modify(int l, int r, int val, int rt = 1) {
        if (l <= tr[rt].l && tr[rt].r <= r) {
            tr[rt].sum = mod(tr[rt].sum * val);
            tr[rt].add = mod(tr[rt].add * val);
            tr[rt].mul = mod(tr[rt].mul * val);
            return;
        }

        push_down(rt);
        int mid =  (tr[rt].l + tr[rt].r) >> 1;

        if (l <= mid) {
            mul_modify(l, r, val, ls);
        }

        if (mid + 1 <= r) {
            mul_modify(l, r, val, rs);
        }

        push_up(rt);
    }

    int query(int l, int r, int rt = 1) {
        if (l <= tr[rt].l && r >= tr[rt].r) {
            return tr[rt].sum;
        }

        push_down(rt);
        int mid = (tr[rt].l + tr[rt].r) >> 1;

        if (r <= mid) return query(l, r, ls);
        if (l > mid) return query(l, r, rs);

        return mod(query(l, r, ls) + query(l, r, rs));
    }
};

void solve() {
    int n, q;
    cin >> n >> q >> m;

    SegTree st(n);
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        st.add_modify(i + 1, i + 1, num);
    }

    int x, y, k;
    for (int i = 0; i < q; ++i) {
        int tag; cin >> tag;
        if (tag == 1) {
            cin >> x >> y >> k;
            st.mul_modify(x, y, k);
        }
        else if (tag == 2) {
            cin >> x >> y >> k;
            st.add_modify(x, y, k);
        }
        else {
            cin >> x >> y;
            cout << st.query(x, y) << "\n";
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
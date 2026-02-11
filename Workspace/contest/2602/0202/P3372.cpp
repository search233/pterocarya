//https://www.luogu.com.cn/problem/P3372

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
        int add;

        node(): l(0), r(0), sum(0), add(0){}
    };

    int len;
    vector<node> info;

    SegTree(const vector<int>& vec) {
        len = vec.size() - 1;
        info.assign(len << 2, node());

        auto build = [&](auto& build, int rt, int l, int r) -> void {
            info[rt].l = l;
            info[rt].r = r;
            
            if (l == r) {
                info[rt].sum = vec[l];
                return;
            }

            int mid = l + r >> 1;
            build(build, ls, l, mid);
            build(build, rs, mid + 1, r);
            push_up(rt);
        };

        build(build, 1, 1, len);
    }   

    void push_up(int rt) {
        info[rt].sum = info[ls].sum+ info[rs].sum;
    }

    void push_down(int rt) {
        if (info[rt].add && info[rt].l != info[rt].r) {

            info[rs].add += info[rt].add;
            info[rs].sum += (info[rs].r - info[rs].l + 1) * info[rt].add;
            
            info[ls].add += info[rt].add;
            info[ls].sum += (info[ls].r - info[ls].l + 1) * info[rt].add;

            info[rt].add = 0;
        }
    }

    void add_modify(int l, int r, int val, int rt = 1) {
        if (info[rt].l >= l && info[rt].r <= r) {
            info[rt].sum += (info[rt].r - info[rt].l + 1) * val;
            info[rt].add += val;
            return;
        }

        int mid = info[rt].l + info[rt].r >> 1;
        push_down(rt);

        if (l <= mid) {
            add_modify(l, r, val, ls);
        }

        if (r >= mid + 1) {
            add_modify(l, r, val, rs);
        }

        push_up(rt);
    }

    int query(int l, int r, int rt = 1) {
        if (l <= info[rt].l && info[rt].r <= r) {
            return info[rt].sum;
        }

        push_down(rt);
        int mid = info[rt].l + info[rt].r >> 1;

        if (r <= mid) return query(l, r, ls);
        if (l > mid) return query(l, r, rs);

        return query(l, r, ls) + query(l, r, rs);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegTree st(a);

    for (int i = 0; i < m; ++i) {
        int tag; cin >> tag;
        if (tag == 1) {
            int x, y, k;
            cin >> x >> y >> k;

            st.add_modify(x, y, k);
        }
        else {
            int x, y; cin >> x >> y;
            cout << st.query(x, y) << '\n';
            // for (int i = 0; i < n; ++i) {
            //     cout << st.query(i + 1, i + 1) << ' ';
            // }
            // cout << '\n';
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
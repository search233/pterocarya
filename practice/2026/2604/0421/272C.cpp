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

struct SegTree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)

    struct Node {
        int l, r;      // 当前节点表示的区间 [l, r]

        // ====== 要维护的信息 ======
        int mx;
        int lazy;
        // ==================================

        Node(): l(0), r(0), mx(0), lazy(-1) {}

        Node operator + (const Node& other) const {
            Node res;
            res.l = l;
            res.r = other.r;
            //直接重载加法实现信息合并

            return res;
        }

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
                tree[rt].mx = vec[l];
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
        tree[rt].mx = max(tree[ls].mx, tree[rs].mx);
    }

    // 下推懒标记：把当前节点的 lazy 影响传给子节点
    void push_down(int rt) {
        if (tree[rt].lazy != -1 && tree[rt].l != tree[rt].r) {
            tree[ls].lazy = tree[rt].lazy;
            tree[ls].mx = tree[rt].lazy;
            tree[rs].lazy = tree[rt].lazy;
            tree[rs].mx = tree[rt].lazy;
            tree[rt].lazy = -1; // 清空当前节点懒标记
        }
    }

    // 区间修改：[L, R] 对区间做某种操作
    void modify(int mxx, int L, int R, int rt = 1) {
        if (L <= tree[rt].l && tree[rt].r <= R) {
            // ====== 整段覆盖时更新, 打标记 ======
            tree[rt].mx = mxx;
            tree[rt].lazy = tree[rt].mx;
            // =========================================
            return;
        }

        push_down(rt);

        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if (L <= mid) modify(mxx, L, R, ls);
        if (R >  mid) modify(mxx, L, R, rs);

        push_up(rt);
    }

    // 区间查询：[L, R] 查询区间信息
    int query(int l, int r, int rt = 1) {
        if (l <= tree[rt].l && tree[rt].r <= r) {
            return tree[rt].mx;
        }

        push_down(rt);
        int mid = tree[rt].l + tree[rt].r >> 1;

        if (r <= mid) return query(l, r, ls);
        if (l > mid) return query(l, r, rs);

        return max(query(l, r, ls), query(l, r, rs));
    }
};


void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegTree segt(a);
    int m; cin >> m;

    for (int i = 1; i <= m; ++i) {
        int w, h; cin >> w >> h;
        int H = segt.query(1, w);
        cout << H << '\n';
        segt.modify(H + h, 1, w);
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
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░
*/
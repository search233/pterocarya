//https://codeforces.com/problemset/problem/145/E

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
        int n4;
        int n7;
        int n47;
        int n74;       
        int trans;     
        // ==================================

        Node(): l(0), r(0), n4(0), n7(0), n47(0), n74(0), trans(0) {}
    };

    int n;
    vector<Node> tree;

    SegTree(const string& s) {
        int len = s.length() - 1;
        tree.assign((len << 2) + 5, Node());

        auto build = [&](auto& build, int rt, int l, int r) -> void {
            tree[rt].l = l;
            tree[rt].r = r;
            
            if (l == r) {
                // 初始化
                if (s[l] == '4') tree[rt].n4 = 1;
                else tree[rt].n7 = 1;
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
        tree[rt].n4 = tree[ls].n4 + tree[rs].n4;
        tree[rt].n7 = tree[ls].n7 + tree[rs].n7;
        tree[rt].n47 = max({tree[ls].n4 + tree[rs].n7, tree[ls].n47 + tree[rs].n7, tree[ls].n4 + tree[rs].n47});
        tree[rt].n74 = max({tree[ls].n7 + tree[rs].n4, tree[ls].n74 + tree[rs].n4, tree[ls].n7 + tree[rs].n74});
        // tree[rt].val = tree[ls].val + tree[rs].val;
        // ==========================================
    }

    // 下推懒标记：把当前节点的 lazy 影响传给子节点
    void push_down(int rt) {
        if (tree[rt].trans != 0 && tree[rt].l != tree[rt].r) {
            // ====== lazy 下传 ======
            tree[ls].trans += tree[rt].trans;
            tree[rs].trans += tree[rt].trans;
            
            if (tree[rt].trans & 1) {
                swap(tree[ls].n4, tree[ls].n7);
                swap(tree[ls].n74, tree[ls].n47);
                swap(tree[rs].n4, tree[rs].n7);
                swap(tree[rs].n74, tree[rs].n47);
            }
            // ====================================

            tree[rt].trans = 0; // 清空当前节点懒标记
        }
    }

    // 区间修改：[L, R] 对区间做某种操作
    void modify(int L, int R, int rt = 1) {
        if (L <= tree[rt].l && tree[rt].r <= R) {
            // ====== 整段覆盖时更新, 打标记 ======
            swap(tree[rt].n4, tree[rt].n7);
            swap(tree[rt].n74, tree[rt].n47);
            ++tree[rt].trans;
            // =========================================
            return;
        }

        push_down(rt);

        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if (L <= mid) modify(L, R, ls);
        if (R >  mid) modify(L, R, rs);

        push_up(rt);
    }

    // 区间查询：[L, R] 查询区间信息
    int query(int rt = 1) {
        return max({tree[rt].n47, tree[rt].n4, tree[rt].n7});
    }
};

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = ' ' + s;
    // cout << s << '\n' << s.length();

    SegTree st(s);

    for (int i = 0; i < m; ++i) {
        string ss; cin >> ss;
        if (ss == "count") {
            cout << st.query() << '\n';
        }
        else if (ss == "switch"){
            int l, r;
            cin >> l >> r;
            st.modify(l, r);
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

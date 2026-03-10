//https://codeforces.com/problemset/problem/380/C

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
        ll ln, rn;
        ll sum;
        // ==================================

        Node(): l(0), r(0), sum(0), ln(0), rn(0) {}

        Node operator + (const Node& other) const {
            Node res;
            res.l = l;
            res.r = other.r;
            ll mn = min(ln, other.rn);
            res.sum = sum + other.sum + 2 * mn;
            res.ln = ln + other.ln - mn;
            res.rn = rn + other.rn - mn;

            return res;
        }
    };

    vector<Node> tree;

    SegTree(const string& s) {
        int len = s.length() - 1;
        tree.assign((len << 2), Node());

        auto build = [&](auto& build, int rt, int l, int r) -> void {
            tree[rt].l = l;
            tree[rt].r = r;
            
            if (l == r) {
                // 初始化
                if (s[l] == '(') tree[rt].ln = 1;
                else tree[rt].rn = 1;
                return;
            }

            int mid = (l + r) >> 1;
            build(build, ls, l, mid);
            build(build, rs, mid + 1, r);
            push_up(rt);
        };

        build(build, 1, 1, len);
    } 

    void print() {
        int cnt = 0;
        for (auto node : tree) {
            cout << cnt++ << ' ';
            cout << node.l << ' ' << node.r << 
            ' ' << node.ln << ' ' << node.rn << '\n';
        }
    }
    // 向上合并
    void push_up(int rt) {
        // ====== 合并左右区间信息 ======
        tree[rt] = tree[ls] + tree[rs];
        // ==========================================
    }

    // 区间查询：[L, R] 查询区间信息
    Node query(int l, int r, int rt = 1) {
        if (l <= tree[rt].l && tree[rt].r <= r) {
            return tree[rt];
        }

        // push_down(rt);
        int mid = (tree[rt].l + tree[rt].r) >> 1;

        if (r <= mid) return query(l, r, ls);
        if (l > mid) return query(l, r, rs);

        Node L = query(l, r, ls);
        Node R = query(l, r, rs);
        return L + R;
    }
};


void solve() {
    string s;
    cin >> s;

    s = ' ' + s;
    SegTree st(s);
    // st.print();

    // cout << s << '\n';
    int q; cin >> q;
    // cout << q;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;        
        cout << st.query(l, r).sum << '\n';
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
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░ 

*/

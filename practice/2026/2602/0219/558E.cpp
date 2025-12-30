//https://codeforces.com/problemset/problem/558/E

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
        vector<int> cnt;
        int tag;
        // ==================================

        Node(): l(0), r(0), tag(-1) {
            cnt.assign(26, 0);
        }
    };

    int n;
    vector<Node> tree;

    SegTree(const string& s) {
        int len = s.length() - 1;
        tree.assign(len << 2, Node());

        auto build = [&](auto& build, int rt, int l, int r) -> void {
            tree[rt].l = l;
            tree[rt].r = r;
            
            if (l == r) {
                // 初始化
                tree[rt].cnt[s[l] - 'a'] = 1;
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
        for (int i = 0; i < 26; ++i) {
            tree[rt].cnt[i] = tree[ls].cnt[i] + tree[rs].cnt[i];
        }
        // ==========================================
    }

    // 下推懒标记：把当前节点的 lazy 影响传给子节点
    void push_down(int rt) {
        if (tree[rt].tag != -1 && tree[rt].l != tree[rt].r) {
            // ====== lazy 下传 ======
            
            tree[ls].tag = tree[rt].tag;
            tree[ls].cnt.assign(26, 0);
            tree[ls].cnt[tree[rt].tag] = (tree[ls].r - tree[ls].l + 1);

            tree[rs].tag = tree[rt].tag;
            tree[rs].cnt.assign(26, 0);
            tree[rs].cnt[tree[rt].tag] = (tree[rs].r - tree[rs].l + 1);
            // ====================================

            tree[rt].tag = -1; // 清空当前节点懒标记
        }
    }

    // 区间修改：[L, R] 对区间做某种操作
    void modify(int L, int R, int ch, int rt = 1) {
        if (L <= tree[rt].l && tree[rt].r <= R) {
            // ====== 整段覆盖时更新, 打标记 ======
            tree[rt].tag = ch;
            tree[rt].cnt.assign(26, 0);
            tree[rt].cnt[ch] = (tree[rt].r - tree[rt].l + 1);
            // =========================================
            return;
        }

        push_down(rt);

        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if (L <= mid) modify(L, R, ch, ls);
        if (R >  mid) modify(L, R, ch, rs);

        push_up(rt);
    }

    // 区间查询：[L, R] 查询区间信息
    int query(int l, int r, int ch, int rt = 1) {
        if (l <= tree[rt].l && tree[rt].r <= r) {
            return tree[rt].cnt[ch];
        }

        push_down(rt);
        int mid = tree[rt].l + tree[rt].r >> 1;

        if (r <= mid) return query(l, r, ch, ls);
        if (l > mid) return query(l, r, ch, rs);

        return query(l, r, ch, ls) + query(l, r, ch, rs);
    }

    void sort(int i, int j, int k) {
        vector<int> ccnt(26);
        for (int ch = 0; ch < 26; ++ch) {
            ccnt[ch] = query(i, j, ch);
        }


        for (int ch = 0; ch < 26; ++ch) {
            if (!ccnt[ch]) continue;
                // cout << i << ' ' << i + ccnt[ch] - 1 << '\n';
            if (k == 1) {
                modify(i, i + ccnt[ch] - 1, ch);
                i += ccnt[ch];
            }
            else {
                modify(j - ccnt[ch] + 1, j, ch);
                j -= ccnt[ch];
            }
        }
    }
};



void solve() {
    int n, q;
    cin >> n >> q;

    string s; cin >> s;
    s = ' ' + s;

    SegTree st(s);

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;

        st.sort(i, j, k);
        // cout << "-----------\n";
    }

    for (int i = 1; i <= n; ++i) {
        for (int ch = 0; ch < 26; ++ch) {
            if(st.query(i, i, ch)) {
                cout << (char)(ch + 'a');
                break;
            }
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

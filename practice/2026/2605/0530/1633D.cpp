#include <bits/stdc++.h>
#include <cassert>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

struct Trie {
    static const int LOG = 30;

    struct Node {
        int ch[2];   // 0/1 两个儿子
        int cnt;     // 经过这个节点的数的个数
        Node() {
            ch[0] = ch[1] = 0;
            cnt = 0;
        }
    };

    vector<Node> tr;

    Trie() {
        tr.reserve(1 << 20);
        tr.push_back(Node()); // 0 号点不用
        tr.push_back(Node()); // 1 号点作为根
    }

    // 插入一个数 x
    void insert(int x) {
        int u = 1;
        tr[u].cnt++;
        for (int k = LOG; k >= 0; --k) {
            int b = (x >> k) & 1;
            if (!tr[u].ch[b]) {
                tr[u].ch[b] = (int)tr.size();
                tr.push_back(Node());
            }
            u = tr[u].ch[b];
            tr[u].cnt++;
        }
    }

    // 删除一个数 x
    // 要求：x 之前一定被插入过，且当前还在 trie 中
    void erase(int x) {
        int u = 1;
        tr[u].cnt--;
        for (int k = LOG; k >= 0; --k) {
            int b = (x >> k) & 1;
            u = tr[u].ch[b];
            tr[u].cnt--;
        }
    }

    // 查询：集合中与 x 异或最大的那个数
    // 返回 {最大异或值, 配对的数}
    pair<int, int> askmax(int x) const {
        int u = 1;
        if (tr[u].cnt == 0) return {x, 0}; // 空集合

        int y = 0;
        for (int k = LOG; k >= 0; --k) {
            int b = (x >> k) & 1;
            int want = b ^ 1; // 想走相反位，使当前位异或为 1

            if (tr[u].ch[want] && tr[tr[u].ch[want]].cnt > 0) {
                y |= (want << k);
                u = tr[u].ch[want];
            } else {
                int go = b;
                y |= (go << k);
                u = tr[u].ch[go];
            }
        }
        return {x ^ y, y};
    }

    // 查询：集合中与 x 异或最小的那个数
    // 返回 {最小异或值, 配对的数}
    pair<int, int> askmin(int x) const {
        int u = 1;
        if (tr[u].cnt == 0) return {-1, -1}; // 空集合

        int y = 0;
        for (int k = LOG; k >= 0; --k) {
            int b = (x >> k) & 1;

            // 想走相同位，使当前位异或为 0
            if (tr[u].ch[b] && tr[tr[u].ch[b]].cnt > 0) {
                y |= (b << k);
                u = tr[u].ch[b];
            } else {
                int go = b ^ 1;
                y |= (go << k);
                u = tr[u].ch[go];
            }
        }
        return {x ^ y, y};
    }

    // 判断当前 trie 是否为空
    bool empty() const {
        return tr[1].cnt == 0;
    }
};

void solve() {
    Trie tree;
    int n; cin >> n;
    tree.insert(0);

    for (int i = 1; i <= n; ++i) {
        char op; cin >> op;
        int x; cin >> x;

        if (op == '+') tree.insert(x);
        else if (op == '-') tree.erase(x);
        else {
            cout << tree.askmax(x).first << '\n';
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
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░
*/
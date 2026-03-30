#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

struct Trie {
    struct node {
        int pass;
        int end;
        int nxt[62];
        node() :pass(0), end(0), nxt{} {}
    };
    
    int cnt = 0;
    vector<node> tree;

    Trie(int n) {
        tree.assign(n + 10, node());
    }

    int cal(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch - 'a'; 
        }
        else if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 26;
        }
        else {
            return ch - '0' + 52;
        }
    }

    void insert(string& s) {
        int p = 0;
        tree[p].pass++;
        for (auto ch : s) {
            int c = cal(ch);
            if (!tree[p].nxt[c]) {                
                tree[p].nxt[c] = ++cnt;
                tree[cnt] = node();
            }
            p = tree[p].nxt[c];
            tree[p].pass++;
        }
        tree[p].end++;
    }
    
    bool find(string& s) {
        int p = 0;
        for (auto ch : s) {
            int c = cal(ch);
            if (!tree[p].nxt[c]) {
                return false;
            }
            p = tree[p].nxt[c];
        }
        return tree[p].end > 0;
    }

    bool erase(string& s) {
        if (!find(s)) {
            return false;
        }    
        int p = 0;    
        tree[p].pass--;    
        for (char ch : s) {
            int c = cal(ch);
    
            p = tree[p].nxt[c];
            tree[p].pass--;
        }
        tree[p].end--;    
        return true;
    }

    void clear() {
        tree[0] = node();
        cnt = 0;
    }

    int cal_prefix(string& s) {
        int p = 0;
        for (auto ch : s) {
            int c = cal(ch);

            if (!tree[p].nxt[c]) {
                return 0;
            }
            p = tree[p].nxt[c];
        }
        return tree[p].pass;
    }
};

Trie tr((int)3e6);

void solve() {
    int n, t;
    cin >> n >> t;
    while (n--) {
        string s; cin >> s;
        tr.insert(s);
    }

    for (int i = 0; i < t; ++i) {
        string s; cin >> s;
        cout << tr.cal_prefix(s) << '\n';
    }

    tr.clear();
}

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

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
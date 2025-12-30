//https://www.luogu.com.cn/problem/P2580

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
    int cnt;
    vector<vector<int>> nex;
    vector<int> exist;  // 该结点结尾的字符串是否存在

    Trie(): cnt(0) {
        nex.assign(500000, vector<int> (26));
        exist.assign(500000, 0);
    }

    void insert(const string& s) {  // 插入字符串
        int l = s.length();
        int p = 0;
        for (auto& ss : s) {
            int c = ss - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    int find(const string& s) {  // 查找字符串
        int p = 0;
        int l = s.length();
        for (auto& ss : s) {
            int c = ss - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        int res = exist[p];
        if (res == 1) exist[p] = 2;
        return res;
    }
};

void solve() {
    int n; cin >> n;
    Trie trie;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        trie.insert(s);
    }

    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        int res = trie.find(s);

        if (res == 0) {
            cout << "WRONG\n";
        }
        else if (res == 2) {
            cout << "REPEAT\n";
        }
        else {
            cout << "OK\n";
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

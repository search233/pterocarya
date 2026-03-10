//https://www.luogu.com.cn/problem/P4551

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
        nex.assign(4000000, vector<int> (2));
        exist.assign(4000000, 0);
    }

    string trans1(const int num) {
        string s;
        for (int i = 30; i >= 0; --i) {
            if ((num >> i) & 1) s.push_back('1');
            else s.push_back('0');
        }
        return s;
    }

    int trans2(string& s) {
        int res = 0;
        reverse(s.begin(), s.end());
        for (int i = 30; i >= 0; --i) {
            if (s[i] == '1') {
                res += (1 << i);
                // cout << i << ' ' <<  res << '\n';
            }
            // cout << s[i];
            // cout << (1 << i) << ' ';
        }
        // cout << '\n';
        return res;
    }

    void insert(const int num) {  // 插入字符串
        string s = trans1(num);
        int p = 0;
        for (auto& ss : s) {
            int c = ss - '0';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = true;
    }

    int find(const int num) {  // 查找字符串
        string s = trans1(num);
        string res;
        int p = 0;

        for (auto& ss : s) {
            int c = ss - '0';
            if (nex[p][c ^ 1]) {
                // cout << c << ' ' << p << ' ' << nex[p][c ^ 1] << '\n';
                res.push_back((c ^ 1) + '0');
                p = nex[p][c ^ 1];
            }
            else {
                res.push_back(c + '0');
                p = nex[p][c];
            }
        }

        // cout << res << '\n';
        return trans2(res);
    }

    void print() {
        for (int i = 0; i < 300; ++i) {
            cout << nex[i][0] << ' ' << nex[i][1] << '\n';
        }
    }
};

void solve() {
    int n; cin >> n;
    vector e(n + 1, vector<arr2>());
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    vector<int> val(n + 1);
    vector<bool> vis(n + 1, 0);
    queue<arr2> qu;
    qu.push({1, 0});
    vis[1] = 1;

    Trie trie;
    while (!qu.empty()) {
        auto [u, w] = qu.front();
        qu.pop();
        
        for (auto [v, ww] : e[u]) {
            if (vis[v]) continue;
            ww ^= w;
            qu.push({v, ww});
            trie.insert(ww);
            val[v] = ww;
            vis[v] = 1;
        }
    }

    int ans = trie.find(0);

    for (int i = 1; i <= n; ++i) {
        // cout << trie.find(val[i]) << '\n';
        ans = max(ans, val[i] ^ trie.find(val[i]));
    }
    cout << ans << '\n';

    // trie.print();
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

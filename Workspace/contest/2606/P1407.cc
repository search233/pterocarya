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
        for (auto& ss : s | views::reverse) {
            int c = ss - 'A';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = true;
    }

    bool find(const string& s) {  // 查找字符串
        int p = 0;
        int l = s.length();
        for (auto& ss : s) {
            int c = ss - 'A';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return exist[p];
    }
};

void solve() {
    Trie trie;
    string ss;
    cin >> ss;
    
    while (ss[0] != '.') {
        trie.insert(ss);
        cin >> ss;
    }

    string s = " ";
    while (cin >> ss) {
        s += ss;
    }

    int n = s.length();
    int ans = 0;

    vector<int> dp(n + 5);
    dp[0] = 1;
    
    for (int i = 1; i < n; ++i) {
        string tmp;
        for (int len = 1; len <= min(10, i); ++len) {
            tmp.push_back(s[i - len + 1]);
            if (trie.find(tmp)) {
                dp[i] |= dp[i - len];
            }

            if (dp[i]) {
                ans = i;
                break;
            }
        }
    }

    cout << ans << '\n';
}
//ABABACABAABC

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
#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();
    vector<int> pre(n + 2), sub(n + 2);
    s = ' ' + s;
    int p = 1;
    for (auto i : t) {
        while (s[p] != i) {
            ++p;
        }
        ++pre[++p];
    }
    p = n;
    for (auto i : ranges::reverse_view(t)) {
        while (s[p] != i) {
            --p;
        }
        ++sub[--p];
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
        // cout << pre[i] << ' ';
    }
    for (int i = n; i > 0; --i) {
        sub[i] += sub[i + 1];
    }

    int ans = 0;
    int l = 1, r = 1;
    while (r <= n) {
        while (r <= n && pre[l] + sub[r] >= m) {
            if (pre[l] + sub[r] == m) {
                ans = max(ans, r - l + 1);
            }

            ++r;
        }
        
        while (l < r && pre[l] + sub[r] < m) {
            ++l;
        }
        if (pre[l] + sub[r] < m) ++r;
    }
    cout << ans;
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
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

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);

    if (n == 1) {
        cout << "0";
        return;
    }
    vector<int> tag(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tag[a[i]] = 0;
    }

    int cnt[2] = {};
    int ccnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (tag[i]) ++cnt[i & 1];
        // cout << tag[i] << ' ' << i << '\n';
        if (i > 1 && a[i] && a[i - 1]) {
            ccnt += ((a[i] & 1) != (a[i - 1] & 1));
        }
    }

    // 0: e, 1: o + e, 2: o
    vector<arr2> b; // typ num
    int l = 0, r = 0;

    while (r < n) {
        while (l < n && a[l + 1]) ++l;
        r = l + 1;
        while (r < n && a[r] == 0) ++r;
        if (!a[l] && !a[r]) {
            cout << "1\n";
            return;
        }
        if (r > n) break;

        if (a[l] && a[r]) {
            b.push_back({(a[l] & 1) + (a[r] & 1), r - l - 1});
        }
        else if (!a[l]) {
            if (a[r] & 1) b.push_back({2, r - l - 1});
            else b.push_back({0, r - l - 1});
        }
        else {
            if (a[l] & 1) b.push_back({2, r - l});
            else b.push_back({0, r - l});
        }
        l = r;
    }

    int m = b.size();

    int memo[101][51][51] = {};
    memset(memo, -1, sizeof(memo));

    auto dfs = [&](this auto&& dfs, int pos, int num0, int num1) -> int {
        if (pos >= m) return 0;

        int& mem = memo[pos][num0][num1];
        if (~mem) return mem;

        int ans = 110;
        int i = max(b[pos][1] - cnt[1] + num1, 0);

        for (; i + num0 <= cnt[0] && i <= b[pos][1]; ++i) {
            int add = 0;

            if ((pos == 0 && a[1] == 0) || (pos == m - 1 && a[n] == 0)) {
                if (b[pos][0] == 0 && i != b[pos][1]) add = 1;
                else if (b[pos][0] == 2 && i != 0) add = 1;
            }
            else if (b[pos][0] == 0) {
                if (i < b[pos][1]) add = 2;
            }
            else if (b[pos][0] == 1) {
                add = 1;
            }
            else {
                if (i) add = 2;
            }

            ans = min(ans, add + dfs(pos + 1, num0 + i, num1 + b[pos][1] - i));
        }
        // cout << pos << ' ' << ans << '\n';
        return mem = ans;
    };

    // cout << cnt[0] << ' ' << cnt[1] << '\n';
    cout << dfs(0, 0, 0) + ccnt;
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
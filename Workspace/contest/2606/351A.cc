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

int dp[4010][2010];
// dp[i][j] 在 i 用了 j 次向上取整

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 2);

    for (int i = 1; i <= n * 2; ++i) {
        string s; cin >> s;
        a[i] += s.back() - '0';
        s.pop_back();
        a[i] += (s.back() - '0') * 10;
        s.pop_back();
        a[i] += (s.back() - '0') * 100;
    }

    auto f = [](int& a, int b) -> void {
        if (abs(a) > abs(b)) a = b;
    };

    memset(dp, 0x3f, sizeof(dp));

    dp[0][0] = 0;
    for (int i = 1; i <= n * 2; ++i) {
        for (int j = 1; j <= min(n, i); ++j) {
            f(dp[i][j], dp[i - 1][j] - a[i]);
            f(dp[i][j], dp[i - 1][j - 1] + (1000 - a[i]) % 1000);
        }
        if (i <= n) dp[i][0] = dp[i - 1][0] - a[i];
    }

    // for (int i = 1; i <= n * 2; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         if (dp[i][j] != 0x3f3f3f3f) cout << dp[i][j];
    //         else cout << "!!!";
    //         cout << " \n"[j == n];
    //     }
    // }

    int ans = abs(dp[n * 2][n]);
    printf("%d.%03d", ans / 1000, ans % 1000);
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
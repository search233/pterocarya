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
    string s; cin >> s;
    int n; cin >> n;

    int len = s.length();
    s = ' ' + s;

    // dp[i][j][k][l]
    // 进行到第 i 个指令
    // 用了 j 次
    // 方向为 k
    // l 方向上的最大值
    int dp[101][51][2][2] = {};
    for (int i = 0; i <= len; ++i) { // 100
        for (int j = 0; j <= n; ++j) { // 50
            for (int k = 0; k <= 1; ++k) { // 2
                dp[i][j][k][0] = 1e9;
                dp[i][j][k][1] = -1e9;  
            }
        }
    }

    dp[0][0][1][0] = dp[0][0][1][1] = 0;
    for (int i = 1; i <= len; ++i) { // 100
        for (int j = 0; j <= n; ++j) { // 50
            for (int k = 0; k <= 1; ++k) { // 2
                if (dp[i - 1][j][k][0] == 1e9) continue;

                for (int t = 0; t + j <= n; ++t) { // 50
                    int jj = t + j;
                    
                    char ch = s[i];
                    if (t & 1) {
                        if (ch == 'F') ch = 'T';
                        else ch = 'F';
                    }

                    int kk = k;
                    int add = 0;
                    if (ch == 'T') kk ^= 1;
                    else {
                        add = k ? 1 : -1;
                    }

                    dp[i][jj][kk][0] = min(dp[i][jj][kk][0], dp[i - 1][j][k][0] + add);
                    dp[i][jj][kk][1] = max(dp[i][jj][kk][1], dp[i - 1][j][k][1] + add);
                }
            }
        }
    }

    int ans = 0;
    for (int k = 0; k < 2; k++) {
        if (dp[len][n][k][0] != 1e9) ans = max(ans, abs(dp[len][n][k][0]));
        if (dp[len][n][k][1] != -1e9) ans = max(ans, abs(dp[len][n][k][1]));
    }
    cout << ans << endl;
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
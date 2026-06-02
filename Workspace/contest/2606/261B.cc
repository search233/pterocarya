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
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int p; cin >> p;
    

    double fac[55] = {1};
    for (int i = 1; i <= 50; ++i) {
        fac[i] = i * fac[i - 1];
    }

    if (sum <= p) {
        cout << n << '\n';
        return;
    }

    double ans = 0;
    for (int i = 1; i <= n; ++i) {

        double dp[55][55] = {};
        dp[0][0] = 1;
        
        for (int x = 1; x <= n; ++x) {
            if (x == i) continue;

            for (int j = n - 1; j > 0; --j) {
                for (int k = p; k >= a[x]; --k) {
                    dp[j][k] += dp[j - 1][k - a[x]];
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int k = max(p - a[i] + 1, 0) ; k <= p; ++k) {
                if (dp[j][k] > 0) {
                    ans += dp[j][k] * fac[j] * fac[n - j - 1] * j;
                }
            }
        }
    }

    printf("%.10f", ans / fac[n]);
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
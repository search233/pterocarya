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
    int n, k; cin >> n >> k;
    vector g(n + 5, vector<int>(n + 5));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c; cin >> c;
            if (c == 'B') {
                g[i][j] = 1;
            }
        }
    }

    int ans = 0;
    vector hang(n + 5, vector<int>(n + 5));
    vector lie(n + 5, vector<int>(n + 5));

    vector cnt(n + 5, vector<int>(n + 5));

    for (int i = 1; i <= n; ++i) {
        int l = -1, r;
        for (int j = 1; j <= n; ++j) {
            if (g[i][j]) {
                if (l == -1) l = j;
                r = j;
            }
        }
        
        if (l == -1) ++ans;
        else if (r - l + 1 <= k) {
            for (int j = max(1, r - k + 1); j <= l; ++j) {
                hang[i][j] = 1;
            }
        }
    }
    
    for (int j = 1; j <= n; ++j) {
        int sum = 0;
        int l = 0, r = 0;
        while (l < n) {
            sum -= (hang[l][j] == 1);
            ++l;

            while (r < n && r - l + 1 < k) {
                ++r;
                sum += (hang[r][j] == 1);
            }

            cnt[l][j] = sum;
        }

    }

    for (int j = 1; j <= n; ++j) {
        int l = -1, r;
        for (int i = 1; i <= n; ++i) {
            if (g[i][j]) {
                if (l == -1) l = i;
                r = i;
            }
        }
        
        if (l == -1) ++ans;
        else if (r - l + 1 <= k) {
            for (int i = max(1, r - k + 1); i <= l; ++i) {
                lie[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        int l = 0, r = 0;
        while (l < n) {
            sum -= (lie[i][l] == 1);
            ++l;

            while (r < n && r - l + 1 < k) {
                ++r;
                sum += (lie[i][r] == 1);
            }

            cnt[i][l] += sum;
        }
    }



    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            res = max(res, cnt[i][j] + ans);
        }
    }

    cout << res << '\n';
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
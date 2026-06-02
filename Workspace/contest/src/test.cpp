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

ll cost[64][64];

ll dp[50][64];

// vector dp(50, vector<ll>(1 << n));



void solve() {

int n, m, k, r;

cin >> n >> m >> k >> r;



vector<arr2> b(n);

for (auto& [a, c] : b) {

cin >> a >> c;

}



    for (int s1 = 0; s1 < (1 << n); ++s1) {

        for (int s2 = 0; s2 < (1 << n); ++s2) {

            cost[s1][s2] = 0;

            for (int l = 0; l < n; ++l) {

                if ((s2 >> l) & 1) {

cost[s1][s2] += b[l][1] + k * ((s1 >> l) & 1);

}

}

}

}



auto cal = [&](int s) -> ll {

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += b[i][0] * ((s >> i) & 1);
    }

    return ans;

};



vector<ll> wight(64);

for (int i = 0; i < (1 << n); ++i) {

wight[i] = cal(i);

}



memset(dp, 0, sizeof(dp));

for (int t = 1; t <= r; ++t) {
    for (int s1 = 0; s1 < (1 << n); ++s1) {

        for(int s2 = 0; s2 < (1 << n); ++s2) {
            if (cost[s1][s2] > m) continue;
            dp[t][s2] = max(dp[t][s2], dp[t - 1][s1] + wight[s2]);
        }

    }

}



ll ans = 0;

for (int i = 0; i < (1 << n); ++i) {

ans = max(ans, dp[r][i]);

}



cout << ans << '\n';

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
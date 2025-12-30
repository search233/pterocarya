//https://codeforces.com/problemset/problem/2185/C

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
    ll n; cin >> n;
    vector a(n, vector<int>());

    map<ll, ll> mp;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int len; cin >> len;
        sum += len;
        a[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> a[i][j];
            ++mp[a[i][j]];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ranges::sort(a[i]);
        ll mx = 0;
        map<int, int> mmp;
        for (auto num : a[i]) {
            ++mmp[num];
            if (num == mx) ++mx;
        }

        for (auto [num, cnt] : mmp) {
            if (num < mx && cnt == 1) {
                ans += num * (n - 1);
            }
            else {
                ans += mx * cnt * (n - 1);
            }
        }

        ll len = a[i].size();        
        ans += mx * (sum - len) * (n - 2);
        ans += (sum - len - mp[mx]) * mx;

        ll temp = mx + 1;
        while(mmp.count(temp)) ++temp;
        ans += mp[mx] * temp;
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

//https://codeforces.com/problemset/problem/2203/C

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
    ll s, m;
    cin >> s >> m;
    
    auto ck = [s, m](ll mid) -> bool {
        ll sum = s;
        for (int i = 63; i >= 0; --i) {
            ll val = (1ll << i);

            if ((m >> i) & 1) {
                ll tmp = min(mid, (sum / val));
                sum -= (tmp * val);
            }

            if (sum == 0) return true;
        }

        return (sum == 0);
    };
    
    ll l = 0, r = 1e18;

    if (!ck(r)) {
        cout << "-1\n";
        return;
    }

    while (l <= r) {
        ll mid = (l + r) >> 1;

        if (ck(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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

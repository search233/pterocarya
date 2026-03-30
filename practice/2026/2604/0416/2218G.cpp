#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

const ll MOD = 676767677;

ll mod(ll num) {
    num %= MOD;
    if (num < 0) num += MOD;
    return num;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<ll> b(n + 2);

    auto cmp = [&](int x, int y) -> bool {
        return b[x] > b[y];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pqu(cmp);

    vector<bool> vis(n + 2);
    map<int, int> mp;

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (b[i] == 0) {
            pqu.push(i);
            vis[i] = 1;
        }
        ++mp[b[i]];
    }

    vector<int> sum(m + 1);
    for (int i = 0; i < m; ++i) {
        sum[i] = mp[i];
        if (i) {
            sum[i] += sum[i - 1];
        }

        // cout << sum[i] - mp[i] << "\n";
    }

    vis[0] = vis[n + 1] = 1;

    ll ans = 1;
    vector<int> t(n + 1); // 满足相邻的时间

    while (!pqu.empty()) {
        int p = pqu.top();
        pqu.pop();
        int T = b[p];

        if (t[p] > T) {
            cout << "0\n";
            return;
        }
        else if (t[p] == T) {
            if (T) ans = mod(ans * sum[T - 1]);
        }
        else { // t[p] < T
            if (T > 1) {
                ans = mod(ans * (sum[T - 1] - sum[T - 2]));
            }
        }

        if (vis[p - 1] == 0) {
            t[p - 1] = T + 1;
            pqu.push(p - 1);
            vis[p - 1] = 1;
        }

        if (vis[p + 1] == 0) {
            t[p + 1] = T + 1;
            pqu.push(p + 1);
            vis[p + 1] = 1;
        }
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
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
    int n; ll k;
    cin >> n >> k;

    map<ll, ll> id;
    vector<ll> p(n + 1), d(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        id[p[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    vector e(n * 2 + 1, vector<int>());
    vector<int> ind(n * 2 + 1);

    auto mod = [&](ll num) -> ll {
        num %= k;
        if (num < 0) num += k;
        return num;
    };

    map<ll, ll> mp;
    for (int i = n; i >= 1; --i) {
        ll tmp = mod(d[i] - p[i]);
        if (mp.count(tmp)) {
            e[i].push_back(mp[tmp]);
            ++ind[mp[tmp]];
        }
        mp[tmp] = i + n;
    }

    mp.clear();
    for (int i = 1; i <= n; ++i) {
        ll tmp = mod(d[i] + p[i]);
        if (mp.count(tmp)) {
            e[i + n].push_back(mp[tmp]);
            ++ind[mp[tmp]];
        }
        mp[tmp] = i;
    }

    vector<ll> pos;
    vector<bool> vis(n * 2 + 1);
    for (int i = 1; i <= n * 2; ++i) {
        if (ind[i] == 0) {
            pos.push_back(i);
            vis[i] = 1;
        }
    }

    for (int i = 0; i < pos.size(); ++i) {
        for (auto v : e[pos[i]]) {
            --ind[v];
            if (ind[v] == 0) {
                pos.push_back(v);
                vis[v] = 1;
            }
        }
    }

    map<ll, set<ll>> mmp;
    for (int i = 1; i <= n; ++i) {
        ll tmp = mod(p[i] - d[i]);
        mmp[tmp].insert(p[i]);
    }

    int q; cin >> q;
    while (q--) {
        ll a; cin >> a;
        ll tmp = mod(a);

        if (!mmp.count(tmp)) {
            cout << "YES\n";
            continue;
        }

        auto pos1 = mmp[tmp].lower_bound(a);
        if (pos1 != mmp[tmp].end() && vis[id[*pos1] + n] == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
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
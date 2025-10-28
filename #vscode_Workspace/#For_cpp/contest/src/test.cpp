#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; 
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& i : a) cin   >> i;

    ranges::sort(a);
    reverse(a.begin(), a.end());

    for (int i=1 ; i<=m ; ++i) {
        cout << a[i - 1] << " \n"[i == m];
    }
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int _ = 1;
    // cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}
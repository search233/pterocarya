#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, k; 
    cin >> n >> k;

    ll sum = 0;

    for (int i=0 ; i<n ; ++i) {
        ll tmp; cin >> tmp;
        sum += tmp;
    }

    cout << sum - n * (n + 1) / 2 << '\n';
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}
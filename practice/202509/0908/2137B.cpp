//https://codeforces.com/problemset/problem/2137/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> p(n), q(n);

    for (auto& i : p) cin >> i;

    for (int i=1 ; i<=n ; ++i) {
        cout << n + 1 - p[i - 1] << " \n"[i == n];
    }
}


int main() {
    int _ = 1;
    cin >> _;

    while (_--) solve();

    return 0;
} 
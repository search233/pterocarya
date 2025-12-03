//https://codeforces.com/problemset/problem/2137/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    map<int, vector<int>> mp;
    vector<int> a(n), res(n);

    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    int cnt = 0;
    for (auto [num, vec] : mp) {

        // cout << num << ' ' << vec.size() << '\n';
        cnt += vec.size() / num;

        if (vec.size() % num) {
            cout << -1 << '\n';
            return;
        }
    }

    // cout << cnt << '\n';

    for (auto [num, vec] : mp) {
        // cout << num << '\n';
        for (int i=0 ; i<vec.size() ; ++i) {
            res[vec[i]] = cnt;
            if (!((i + 1) % num)) --cnt;
        }
    }

    for (int i=0 ; i<n ; ++i) {
        cout << res[i] << " \n"[i == n-1];
    }
}


int main() {
    int _ = 1;
    cin >> _;

    while (_--) solve();

    return 0;
} 
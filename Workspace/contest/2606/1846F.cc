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

void solve() {
    int n; cin >> n;
    map<int, int> mp1;

    for (int i = 1; i <= n; ++i) {
        int num; cin >> num;
        ++mp1[num];
    }

    cout << "- 0" << endl;

    map<int, int> mp2;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++mp2[a[i]];
    }

    if (mp1 == mp2) {
        cout << "- 0" << endl;
        mp2.clear();
        a.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++mp2[a[i]];
        }
    }

    int tmp = 0;
    for (auto [num, cnt] : mp2) {
        if (cnt > mp1[num]) {
            tmp = num;
        }
    }

    cout << "- " << n - mp2[tmp];
    for (int i = 1; i <= n; ++i) {
        if (a[i] != tmp) cout << ' ' << i;
    }
    cout << endl;

    n = mp2[tmp];

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        int num; cin >> num;
        if (num != tmp) ans = i;
    }

    if (ans != -1) {
        cout << "! " << ans << endl;
        return;
    }

    cout << "- 0" << endl;
    for (int i = 1; i <= n; ++i) {
        int num; cin >> num;
        if (num != tmp) ans = i;
    }

    cout << "! " << ans << endl;
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
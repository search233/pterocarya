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

    vector pos(2, vector<arr2>());

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pos[((i & 1) == (j & 1))].push_back({i, j});
        }
    }
    

    // pos[1] --> c: 1 (same)
    // pos[0] --> c: 2

    auto put = [&](int typ, int b) -> void {
        auto [x, y] = pos[typ].back();
        pos[typ].pop_back();
        cout << b << ' ' << x << ' ' << y << endl;
    };

    for (int t = 0; t < n * n; ++t) {
        int c; cin >> c;
        arr3 ans;
        if (c == 1) {
            if (!pos[0].empty()) {
                put(0, 2);
            }
            else {
                put(1, 3);
            }
        }
        else if (c == 2) {
            if (!pos[1].empty()) {
                put(1, 1);
            }
            else {
                put(0, 3);
            }
        }
        else {
            if (!pos[1].empty()) {
                put(1, 1);
            }
            else {
                put(0, 2);
            }
        }
    }
}

int main() {
    
    __BUFF__

    int _ = 1;
    // cin >> _;

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
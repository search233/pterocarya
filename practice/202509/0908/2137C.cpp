//https://codeforces.com/problemset/problem/2137/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;

    if ((a & 1) && (b & 1)) {
       cout << a * b + 1 << '\n';
    }
    else if (b & 1) {
        cout << -1 << '\n';
    }
    else if (a & 1) {
        if (b % 4) {
            cout << -1 << '\n';
        }
        else {
            cout << 2 + ((a * b) >> 1ll) << '\n';
        }
    } 
    else {
        cout << 2 + ((a * b) >> 1ll) << '\n';
    }

     
}


int main() {
    int _ = 1;
    cin >> _;

    while (_--) solve();

    return 0;
} 
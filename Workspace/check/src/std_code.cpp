#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve () {
    // //cout << (1 << 30) << "\n";
    // for (int i = (1 << 27); i >= 0; i--) {
    //     if (i % 3 == 0 && i % 2 == 0) {
    //         if ((i / 2) != sqrt(i / 2) * sqrt(i / 2)) continue;
    //         for (int j = 1; j < sqrt(i / 3); j++) {
    //             if (j * j * j == i / 3) {
    //                 cout << i << "\n";
    //                 return ;
    //             }
    //         }
    //     }
    // }
    int n; cin >> n;
    bool f1 = 0, f2 = 0;
    for (int p = 1; p * p <= n; p++) {
        if (2 * p * p == n) {
            f1 = 1;
        }
        if (3 * p * p * p == n) {
            f2 = 1;
        }
    }
    if (f1 && f2) {
        cout << n << " is a triple flower\n";
    }
    else if (f1) {  
        cout << n << " is a double flower\n";
    }
    else cout << n << " is " << n << "\n";
        
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
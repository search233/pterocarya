#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int a = x / 2;
        int aa = x % 2;
        bool f1 = 0;
        if (aa == 0) {
            if (a == (int)sqrt(a) * sqrt(a)) {
                f1 = 1;
                cout <<sqrt(a) <<  "   !!!!\n";
            }
        }

        int b = x / 3;
        int bb = x % 3;
        bool f2 = 0;
        if (bb == 0) {
            for (int j = sqrt(x); j >= 0; j--) {
                if (j * j * j == b) {
                    f2 = 1;
                    break;
                }
            }
        }
        if (f1 && f2) {
            cout << x << " is a triple flower\n";
        }
        else if (f1) {  
            cout << x << " is a double flower\n";
        }
        //else if (f2) cout << x << " is a triple flower\n";
        else cout << x << " is " << x << "\n";

    }

    
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
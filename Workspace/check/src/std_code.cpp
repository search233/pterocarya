#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using i128 = __int128;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mn = a[1];
    int ans = 1;
    bool f = 0, ff = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1] + 1) {
            f = 0;
            ff = 0;
            mn = a[i];
            ans++;
            continue;
        }
        // if (ff && a[i] > a[i - 1]) {
        //     f = 0;
        //     ff = 0;
        //     mn = a[i];
        //     ans++;
        //     continue;
        // }
        if (a[i] == a[i - 1] + 1) {
            f = 1;
            continue;
        }
        if (f && a[i] == a[i - 1]) {
            continue;
        }
        if (f && a[i] >= mn + 1) {
            ff = 1;
            continue;
        }
        f = 0;
        ff = 0;
        mn = a[i];
        ans++;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}
/*
*   /\_/\
*  (= ._.)
*  / >  \>
*/
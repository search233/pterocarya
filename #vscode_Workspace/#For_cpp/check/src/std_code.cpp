#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 5), b(m + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + m);
    int num1 = 0, num2 = 0;
    bool f = 0, f1 = 0;
    int l = n + 1;
    for (int i = 1; i <= n; i++) {
        if (!f1 && a[i] != 1) {
            l = i;
            f1 = 1;
        }
        if (!f && a[i] == 1) {
            num1++;
            f = 1;
            a[i] -= 1;
            num2++;
        }
        else if (f && a[i] == 1) {
            a[i] -= 1;
            num2++;
        }
        if (a[i] > 1) {
            num1++;
            a[i] -= 1;
        }
    }
    //cout << num1 << " " << num2 << "\n";
    while (l <= n && a[l] <= num2) {
        l++;
        num2++;
    }
    f = 0;
    //cout << num1 << " " << num2 << "\n";
    for (int i = 1; i <= m; i++) {
        if (num2 >= b[i]) {
            num2++;
            while (l <= n && a[l] <= num2) {
                l++;
                num2++;
            }
            continue;
        }
        if (num1 + num2 >= b[i]) {
            num1 -= b[i] - num2;
            num2++;
            while (l <= n && a[l] <= num2) {
                l++;
                num2++;
            }
            continue;
        }
        f = 1;
        break;
    }
    if (f) {
        cout << "No\n";
        return ;
    }
    cout << "Yes\n";
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
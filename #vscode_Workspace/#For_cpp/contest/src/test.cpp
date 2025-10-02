#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);

double a[N], b[2 * N];

void solve() {
    int n, k;
    cin >> n >> k;
    k++;

    int lena = 0; // a 的长度
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        if (y > 0) {
            if (x == 0) a[lena++] = pi / 2;
            else if (x > 0) a[lena++] = atan(y / x);
            else a[lena++] = pi - atan(y / abs(x));
        }
        else if (y < 0) {
            if (x == 0) a[lena++] = pi / 2 + pi;
            else if (x > 0) a[lena++] = 2 * pi - atan(abs(y) / x);
            else a[lena++] = atan(y / x) + pi;
        }
        else {
            if (x > 0) a[lena++] = 0;
            else a[lena++] = pi;
        }
    }

    sort(a, a + lena);

    int lenb = 0;
    for (int i = 0; i < lena; i++) b[lenb++] = a[i];
    for (int i = 0; i < lena; i++) b[lenb++] = a[i];

    int r = 0;
    double mnl = 0, mnr = 0, mx = 0;
    for (int i = 0; i < lena; i++) {
        // while (r < lenb && r - i + 1 < k) {
        //     r++;
        // }
        // if (r == lenb) break;

        r = i + k - 1;
        double cha = 0;
        if (r < lena) {
            cha = b[r] - b[i];
        } else {
            cha = 2 * pi - b[i] + b[r];
        }

        if (cha > mx) {
            mx = cha;
            mnr = r;
            mnl = i;
        }
    }
    printf("%.7lf\n", mx);
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
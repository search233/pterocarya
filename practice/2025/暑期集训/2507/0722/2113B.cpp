//https://codeforces.com/problemset/problem/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

int a[N];

void solve() {
    int w, h, a, b;
    cin >> w >> h >> a >> b;

    int x1_l, x2_l, y1_d, y2_d;
    cin >> x1_l >> y1_d >> x2_l >> y2_d;

    int x1_r = x1_l + a;
    int y1_u = y1_d + b;
    int x2_r = x2_l + a;
    int y2_u = y2_d + b;

    if (x1_r <= x2_l && (x2_l - x1_r) % a == 0) {
        cout << "YES" << '\n';
        return;
    }

    if (x1_l >= x2_r && (x1_l - x2_r) % a == 0) {
        cout << "YES" << '\n';
        return;
    }

    if (y1_u <= y2_d && (y2_d - y1_u) % b == 0) {
        cout << "YES" << '\n';
        return;
    }

    if (y2_u <= y1_d && (y1_d - y2_u) % b == 0) {
        cout << "YES" << '\n';
        return;
    }

    cout << "NO" << '\n';

}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--)
        solve();

    return 0;
}

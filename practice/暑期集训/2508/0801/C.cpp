//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)5e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

ll j[N];
ll f[N][4];

void precul(){
    j[0] = 1;
    f[1][1] = 1;
    f[1][2] = 1;
    f[1][3] = 1;

    for (ll i=2 ; i<=5e5 ; ++i) {
        j[i - 1] = (j[i - 2] * (i - 1ll)) % mod;
        f[i][1] = ((i * f[i - 1][1]) % mod + j[i - 1]) % mod;
        f[i][2] = (((i * f[i - 1][2]) % mod + (2 * f[i - 1][1]) % mod) % mod + j[i - 1]) % mod;
        f[i][3] = ((((i * f[i - 1][3]) % mod + (3 * f[i - 1][2]) % mod) % mod + (3 * f[i - 1][1]) % mod ) % mod + j[i - 1]) % mod;
    }
}


void solve() {
    int n; cin >> n;

    cout << f[n][3] << '\n';
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precul();

    int _T = 1;
    cin >> _T;

    while (_T--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*



  /\_/\
 (= ._.)
 / >  \>

*/
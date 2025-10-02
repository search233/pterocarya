//https://codeforces.com/problemset/problem/2051/B
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

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int sum = a+b+c;

    int res = n/sum;

    n -= sum * res;
    
    res *= 3;

    if (n > 0) {
        if (n - a <= 0) res += 1;
        else if (n -a - b <= 0) res += 2;
        else res += 3;
    }


    cout << res << '\n';
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

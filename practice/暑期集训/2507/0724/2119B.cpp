//https://codeforces.com/problemset/problem/2119/B

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
    vector<int> a;
    int n; cin >> n;
    double p_x, p_y, q_x, q_y;
    cin >> p_x >> p_y >> q_x >> q_y;

    double L = sqrt((p_x - q_x) * (p_x - q_x) + (p_y - q_y) * (p_y - q_y));
    int sum = 0;
    int maxn = 0;
    for (int i=0 ; i<n ; ++i) {
        int tmp;
        cin >> tmp;

        maxn = max(maxn, tmp);
        sum += tmp;
    }

    if (sum < L) {
        cout << "NO\n";
        return;
    }
    sum -= maxn;

    // cout << L << ' ' << sum << ' ' << maxn << '\n';

    if (maxn > sum + L) cout << "NO\n";
    else cout << "YES\n";
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

//https://codeforces.com/problemset/problem/1268/A

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
    int n, k;
    cin >> n >> k;

    string tx;
    cin >> tx;

    string x = tx;
    
    for (int i=k ; i<n ; ++i) {
        x[i] = x[i - k];
    }


    if (x >= tx) {
        cout << n << '\n';
        cout << x << '\n';
        return;
    }

    int pos = k - 1;
    ++x[pos];
    while (x[pos] > '9') {
        x[pos] = '0';
        ++x[--pos];
    }

    for (int i=k ; i<n ; ++i) {
        x[i] = x[i - k];
    }
    cout << n << '\n';
    cout << x;
    cout << '\n';

} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    // cin >> _T;

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
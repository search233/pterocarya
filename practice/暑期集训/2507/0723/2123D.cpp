//https://codeforces.com/problemset/problem/2123/D
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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int minn = INT_MAX;
    int maxk = 0;
    int cnt = 0;
    for (int i=0 ; i<n ; ++i) {
        if (s[i] == '1') {
            ++cnt;
        }
    }
    
    if (cnt <= k || k > n/2)
        cout << "Alice\n";
    else 
        cout << "Bob\n";
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

//https://codeforces.com/problemset/problem/2122/A
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
    int m, n;
    cin >> n >> m;

    if (n == 1 || m == 1 || (n==2 && m==2)) 
        cout << "NO\n";
    else 
        cout << "YES\n";
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

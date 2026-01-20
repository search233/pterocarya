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
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<arr2> p(n + 5);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i][0];
        sum += p[i][0];
    }
    int cnta = 0, cntb = 0;
    int cba = 0, cbb = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            cnta++;
            p[i + 1][1] = 0;
            cba += p[i + 1][0] / 2 + 1;
        }
        else {
            cntb++;
            p[i + 1][1] = 1;
            cbb += p[i + 1][0] / 2 + 1;
        }
    }
    if (cnta == n) {
        if (x - y < cnta) {
            cout << "NO\n";
            return ;
        }
    }
    if (cntb == n) {
        if (y - x < cntb) {
            cout << "NO\n";
            return ;
        }
    }
    if (x < cnta || y < cntb || x < cba || y < cbb) {
        cout << "NO\n";
        return ;
    } 
    if (sum > x + y) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
    // sort(p.begin() + 1, p.begin() + 1 + n);
    // vector<int> aa, bb;
    // for (int i = 1; i <= n; i++) {
    //     if (p[i][1] == 0) {

    //     }
    // }
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
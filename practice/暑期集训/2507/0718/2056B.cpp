//https://codeforces.com/problemset/problem/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)1e3 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

pii p[N];

int cmp(pii a, pii b) { return a.second > b.second; }

void solve() {
    int n; 
    cin >> n;

    for (int i=1 ; i<=n ; ++i) {
        int psum = 0;
        int ssum = 0;

        string s;
        cin >> s;

        for (int j=1 ; j<=n ; ++j) {
            int tmp = s[j-1] - '0';

            if (j < i) psum += tmp;
            else       ssum += tmp;
        }

        p[i] = {i, ssum + i - psum - 1};
    }

    sort(p+1, p+1+n, cmp);

    for (int i=1 ; i<=n ; ++i)
        cout << p[i].first << ' ';

    cout << '\n';
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
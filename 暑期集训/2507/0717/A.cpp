//https://codeforces.com/problemset/problem/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)5e5 + 9;
const int M = (int)1e5 + 9;
const int mod = 998244353;
const ll INF = LLONG_MAX;

int pow2[N] = {1};

void pre_cul() {
    for (int i=1 ; i<=N ; ++i)
        pow2[i] = (pow2[i-1] * 2) % mod;
}


void solve() {
    int n; cin >> n;
    
    int k = 0;
    ll res = 0;

    vector<int> a;
    a.push_back(0);

    for (int i=0 ; i<n ; ++i) {
        int tnum; cin >> tnum;
        a.push_back(tnum);
        if (tnum == -1)
            ++k;
    }

    for (int i=0 ; i<n ; ++i) {
        if ((a[i]==0 || a[i]==-1) && (a[i+1]==1 || a[i+1]==-1)) {
            res = (res + pow2[k+a[i]+min(0,a[i+1])]) % mod;
        }
    }

    cout << res << '\n';
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    pre_cul();

    while (_T--)
        solve();

    return 0;
}
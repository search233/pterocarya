//https://codeforces.com/problemset/problem/2126/D
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

struct Node {
    int l;
    int r;
    int real;
}cas[M];

int cmp(Node a, Node b) { return a.l < b.l; }

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i=0 ; i<n ; ++i) {
        cin >> cas[i].l
            >> cas[i].r
            >> cas[i].real;
    }

    sort(cas, cas+n, cmp);

    for (int i=0 ; i<n ; ++i) {
        if (cas[i].l <= k && cas[i].r >= k && cas[i].real > k) 
            k = cas[i].real; 
    }

    cout << k << '\n';
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
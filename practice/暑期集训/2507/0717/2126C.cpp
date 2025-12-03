//https://codeforces.com/problemset/problem/2126/C
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

    vector<int> h;
    int H;

    for (int i=0 ; i<n ; ++i) {
        int th; cin >> th;
        h.push_back(th);
        if (i+1 == k) 
            H = th;
    }

    int t = H;

    sort(h.begin(), h.end());

    for (int i=0 ; i<n-1 ; ++i) {
        if (h[i] < H)
            continue;
        
        int t1 = h[i+1] - h[i];
        if (t1 > t) {
            cout << "NO" << '\n';
            return ;
        }
    }

    cout << "YES" << '\n';
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
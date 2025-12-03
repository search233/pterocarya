//https://codeforces.com/problemset/problem/2117/C
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
    int n; cin >> n;

    map<int, vector<int>> mp;
    vector<int> nxt(n+1);
    vector<int> a(n);

    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    for (auto [num, vec] : mp) {
        nxt[vec.back()] = vec.back();

        for (int i=0 ; i<vec.size() - 1 ; ++i)
            nxt[vec[i]] = vec[i + 1];
    }

    int ans = 1;
    int l = 1;
    int r = nxt[0];

    while (r >= l) {

        ++ans;
        int maxl = nxt[r];

        for (int i=l ; i<=r ; ++i) {
            maxl = max(nxt[i], maxl);

            if (nxt[i] == i) {
                cout << ans << '\n';
                return;
            }
        }

        l = r + 1;
        r = maxl;
    }

    cout << 1 << '\n';
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*
*   /\_/\
*  (= ._.)
*  / >  \>
*/
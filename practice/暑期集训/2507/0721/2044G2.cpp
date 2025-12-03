//https://codeforces.com/problemset/problem/2044/G2
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, ll>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

int r[N];
vector<ll> res[N];
int incnt[N];

void solve() {

    // ll res = 0;
    int n; cin >> n;

    for (int i=1 ; i<=n ; ++i) {
        incnt[i] = 0;
        res[i].clear();
    }

    for (int i=1 ; i<=n ; ++i) {
        cin >> r[i];
        ++incnt[r[i]];
    }


    queue<pii> qu;

    for (int i=1 ; i<=n ; ++i) {
        if (incnt[i] == 0) 
            qu.push(pii{i, 1});
    }

    while (!qu.empty()) {
        auto it = qu.front();
        qu.pop();

        int pos = r[it.first];
        ll sum = it.second;

        --incnt[pos];

        if (incnt[pos] == 0) {

            for (int i=0 ; i<res[pos].size() ; ++i) 
                sum += res[pos][i];

            qu.push({pos, sum+1});

        } else  res[pos].push_back(sum);
    }

    ll ans = 0;

    for (int i=1 ; i<=n ; ++i) {
        if (incnt[i] != 0) {

            if (res[i].size() > 0) {
                sort(res[i].begin(), res[i].end());
                ans = max(res[i].back(), ans);
            }
        }
    }

    cout << ans+2 << '\n';
    
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

//https://ac.nowcoder.com/acm/contest/108298/L

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const ll mod = (ll)1e9 + 7;
const ll INF = LLONG_MAX;

ll a[N];

void solve()
{
    int n; cin >> n;
    int q; cin >> q;

    map<ll, int> mp;

    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        ++mp[a[i]];
    }

    auto it = mp.begin();

    int res = 0;
    int mid = (n+1)/2;

    while ((res + it->second) <= mid) {
        res += it->second;
        ++it;
    }

    for (int i=0 ; i<q ; ++i) {
        int p, v;
        cin >> p >> v;

        --mp[a[p]];
        ++mp[a[p]+v];

        if ( a[p] < it->first && (a[p]+v) >= it->first) {
            --res;
        }

        while ((res + it->second) <= mid) {
            res += it->second;
            ++it;
        }

        a[p] += v;
        cout << res << '\n';
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--)
    {
        solve();
    }

    return 0;
}
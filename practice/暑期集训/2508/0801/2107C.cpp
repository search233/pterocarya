//https://codeforces.com/problemset/problem/2107/C
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF =  (ll)1e13;

void solve() {
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    s = '0' + s;
    s += '0';

    vector<ll> a(n + 2);
    vector<int> pos;

    for (int i=0 ; i<s.length() ; ++i)
        if (s[i] == '0') pos.push_back(i);

    for (int i=1 ; i<=n ; ++i) cin >> a[i];

    int mid, r = 0, l;
    ll maxn = -INF;

    for (int i=1 ; i<pos.size() ; ++i) {
        ll tmp = -INF;
        ll tmx = -INF;

        for (int l=pos[i-1] ; l<pos[i] ; ++l) {
            tmp = max(a[l], a[l] + tmp);
            tmx = max(tmx, tmp);
        } 

        if (tmx > maxn) {
            maxn = tmx;
            r = i;
        }
    }

    if (maxn > k || (maxn < k && pos.size() == 2)) {
        cout << "No\n";
        return;

    }
    
    if (maxn == k) {
        for (int i=1 ; i<=n ; ++i)
            if (s[i] == '0') 
                a[i] = -INF;

    } else {
        if (pos[r] == n+1) --r;
        mid = pos[r];

        l = pos[r-1];
        r = pos[r+1];

        auto check = [&]() -> ll {
            ll tmx = -INF;
            ll cur = -INF;

            for (int i=l+1 ; i<r ; ++i) {
                cur += a[i];
                cur = max(cur, a[i]);

                tmx = max(tmx, cur);
            }
            return tmx;
        };

        ll pl = (ll)-1e18;
        ll pr = (ll)1e18;

        while (pl <= pr) {
            a[mid] = ((pl + pr) >> 1);
            ll vul = check();

            if (vul > k) {
                pr = a[mid] - 1;
            } else if (vul < k) {
                pl = a[mid] + 1;
            }else {
                break;
            }
        }
    } 

    cout << "Yes\n";
    for (int i=1 ; i<=n ; ++i) {
        if (s[i] == '0' && i != mid) cout << -INF << ' ';
        else cout << a[i] << ' ';
    }
        
    cout << '\n';
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

    if (pos.size() <= 2) {
        ll tmaxn = a[1];
        for (int i=2 ; i<=n ; ++i) {
            tmaxn += a[i];
            tmaxn = max(a[i],tmaxn);
        }

        if (tmaxn != k) cout << "No\n";
        else {
            cout << "Yes\n";
            for (int i=1 ; i<=n ; ++i) cout << a[i] << ' ';
            cout << '\n';
        }

        return;
    }

  /\_/\
 (= ._.)
 / >  \>

*/
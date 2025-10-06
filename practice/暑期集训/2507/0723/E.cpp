//https://ac.nowcoder.com/acm/contest/108300/E

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)5e6 + 9;
const int M = (int)5e6 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

int a[M];
int prime[N], cnt = 0, minp[N];
int vis[N];

void solve() {
    
    int n; cin >> n;

    unordered_map<int, int> mp;
    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
        int tmp = a[i];

        while(tmp != 1){
            mp[minp[tmp]]++;
            tmp /= minp[tmp];
            if(tmp==1)break;
        }
    }

    if (n & 1) {
        cout << "YES\n";
        return;
    }

    if (n == 2) {
        if (a[0] == a[1])
            cout << "YES\n";
        else
            cout << "NO\n";

        return;
    }

    for (auto [num, numcnt] : mp) {
        if (numcnt & 1) {
            cout << "NO\n";
            return;
        }

        // cout << num << ' ' << numcnt << '\n';
    }

    cout << "YES\n";
}
    
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int _T = 1;
    cin >> _T;
    minp[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) prime[++cnt] = i, minp[i] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
            vis[i * prime[j]] = 1;
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }

    while (_T--)
        solve();

    return 0;
}

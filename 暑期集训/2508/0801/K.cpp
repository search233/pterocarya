//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)1e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

vector<int> fac[N];

void solve() {
    int n; cin >> n;

    vector<int> a(n + 1);

    int g = 0;
    int cnt = 0;
    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        if (i > 1) g = __gcd(abs(a[i] - a[i-1]), g);

        if (a[i] == a[1]) ++cnt;
    }

    int res = g;

    if (cnt == n) {
        cout << 0 << '\n';
        return;
    }

    int tag;

    for (auto f : fac[a[1]]) {
        deque<int> ff;
        tag = 1;

        for (int i=1 ; i<=n ; ++i) 
            ff.push_back(a[i] % f);
        
        while (!ff.empty() && ff.front() == 0) ff.pop_front();
        while (!ff.empty() && ff.back() == 0)  ff.pop_back();

        for (int i=0 ; i<ff.size() ; ++i) {
            if (ff[i] != ff.front()) {
                tag = 0;
                break;
            }
        }

        if (tag) res = max(res, f);
    }

    for (auto f : fac[a[n]]) {
        deque<int> ff;
        tag= 1;

        for (int i=1 ; i<=n ; ++i)
            ff.push_back(a[i] % f);

        while (!ff.empty() && ff.front() == 0) ff.pop_front();
        while (!ff.empty() && ff.back() == 0)  ff.pop_back();

        for (int i=0 ; i<ff.size() ; ++i) {
            if (ff[i] != ff[0]) {
                tag = 0;
                break;
            }
        }

        if (tag) res = max(res, f);
    }
    
    cout << res << '\n';
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    for (int i=1 ; i<=1e5 ; ++i) {
        for (int j=i ; j<=1e5 ; j += i){
            fac[j].push_back(i);
        }
    }

    while (_T--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*



  /\_/\
 (= ._.)
 / >  \>

*/
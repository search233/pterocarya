//https://codeforces.com/problemset/problem/2086/C
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

struct Dsu {
    vector<int> _p, _sz;

    Dsu(int n) {
        _p.resize(n+1);
        _sz.resize(n+1);
        init(n);
    }

    void init(int n) {
        for (int i=0 ; i<=n ; ++i) {
            _p[i] = i;
            _sz[i] = 1;
        }
    }

    int find(int x) {
        while (x != _p[x]) {
            x = _p[x] = _p[_p[x]];
        }
        return x;
    }
 
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        _p[fy] = fx;
        _sz[fx] += _sz[fy];
        return true;
    }
 
    bool same(int x, int y) {
        return find(x) == find(y);
    }
 
    int size(int x) {
        return _sz[find(x)];
    }
};

int p[N];
int d[N];

void solve() {

    int n; cin >> n;
    Dsu dsu(n);

    for (int i=1 ; i<=n ; ++i) {
        cin >> p[i];
        dsu.merge(p[i], i);
    }

    for (int i=1 ; i<=n ; ++i)
        cin >> d[i];
        
    int res = 0;
    for (int i=1 ; i<=n ; ++i) {
        int fa = dsu.find(p[d[i]]);
        
        res += dsu._sz[fa];
        dsu._sz[fa] = 0;

        cout << res << ' ';
    }
    
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


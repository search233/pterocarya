//https://codeforces.com/problemset/problem/2060/E

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

int fa_f[N];
int fa_g[N];

int find_f(int x) {
    if (fa_f[x] == x) return x;
    else return fa_f[x] = find_f(fa_f[x]);
}

int find_g(int x) {
    if (fa_g[x] == x) return x;
    else return fa_g[x] = find_g(fa_g[x]);
}

void solve()
{
    int n; cin >> n;

    int sum_f = n;
    int sum_g = n;

    int m1, m2;
    cin >> m1 >> m2;

    for (int i=0 ; i<=n ; ++i) {
        fa_g[i] = i;
        fa_f[i] = i;
    }

    vector<pii> F;

    int u, v;
    int fu, fv;
    for (int i=0 ; i<m1 ; ++i) {
        cin >> u >> v;
        F.push_back({u, v});
    }

    for (int i=0 ; i<m2 ; ++i) {
        cin >> u >> v;      
        fu = find_g(u);
        fv = find_g(v);

        if (fu != fv) {
            --sum_g;
            fa_g[fu] = fv;
        }
    }

    int res = 0;
    for (auto [u, v] : F) {
        fu = find_g(u);
        fv = find_g(v);

        if (fu != fv) ++res;
        else {
            fu = find_f(u);
            fv = find_f(v);
            if (fu != fv) {
                --sum_f;
                fa_f[fu] = fv;
            }
        }
    }

    // for (int i=1 ; i<=n ; ++i) {
    //     if (find_f(i) == i) ++sum_f;
    //     if (find_g(i) == i) ++sum_g;
    // }

    cout << res + sum_f - sum_g << '\n';
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


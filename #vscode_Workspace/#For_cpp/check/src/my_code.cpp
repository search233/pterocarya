#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, q;
    cin >> n >> q;
    
    vector<vector<int>> a(n, vector<int>(4, 0));

    int cnt = 0;
    for (auto& i : a) {
        cin >> i[1] >> i[2] >> i[3];
        i[0] = cnt;
        ++cnt;  
    }

    auto cmp1 = [&](vector<int> x, vector<int> y) -> bool {
        return x[1] > y[1];
    }; 

    auto cmp2 = [&](vector<int> x, vector<int> y) -> bool {
        return x[2] > y[2];
    };

    auto cmp3 = [&](vector<int> x, vector<int> y) -> bool {
        return x[1]*y[3] > y[1]*x[3];
    };

    auto cmp4 = [&](vector<int> x, vector<int> y) -> bool {
        return x[2]*y[3] > y[2]*x[3];
    };


    vector<vector<int>> rk(n + 1, vector<int> (2, n));

    sort(a.begin(), a.end(), cmp1);
    int trk = 1;
    for (int i=0 ; i<n ; ++i) {
        if (i && a[i - 1][1] > a[i][1]) {
            trk = i + 1;
        }
        if (rk[a[i][0]][0] > trk) {
            rk[a[i][0]][1] = 1;
            rk[a[i][0]][0] = trk;
        }
    }

    sort(a.begin(), a.end(), cmp2);
    trk = 1;
    for (int i=0 ; i<n ; ++i) {
        if (i && a[i - 1][2] > a[i][2]) {
            trk = i + 1;
        }
        if (rk[a[i][0]][0] > trk) {
            rk[a[i][0]][1] = 2;
            rk[a[i][0]][0] = trk;
        }
    }

    sort(a.begin(), a.end(), cmp3);
    trk = 1;
    for (int i=0 ; i<n ; ++i) {
        if (i && a[i - 1][1]*a[i][3] > a[i][1]*a[i - 1][3]) {
            trk = i + 1;
        }
        if (rk[a[i][0]][0] > trk) {
            rk[a[i][0]][1] = 3;
            rk[a[i][0]][0] = trk;
        }
    }

    sort(a.begin(), a.end(), cmp4);
    trk = 1;
    for (int i=0 ; i<n ; ++i) {
        if (i && a[i - 1][2]*a[i][3] > a[i][2]*a[i - 1][3]) {
            trk = i + 1;
        }
        if (rk[a[i][0]][0] > trk) {
            rk[a[i][0]][1] = 4;
            rk[a[i][0]][0] = trk;
        }
    }
    for (int i=0 ; i<q ; ++i) {
        int p; cin >> p;

        cout << rk[p][0] << ':' << rk[p][1] << " \n"[i == q-1];
    }
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int _ = 1;
    // cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}
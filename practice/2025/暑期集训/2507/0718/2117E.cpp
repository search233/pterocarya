//https://codeforces.com/problemset/problem/2117/E
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

int a[N];
int b[N];

map<int, vector<int>> mp;

void solve() {

    int res = 0;
    int n; cin >> n;

    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i+1);

        if (i > 0 && a[i] == a[i-1])
            res = max(res, i);
    }
        
    for (int i=0 ; i<n ; ++i) {
        cin >> b[i];
        mp[b[i]].push_back(i+1);

        if (a[i] == b[i])
            res = max(res, i+1);

        if (i > 0 && b[i] == b[i-1])
            res = max(res, i);       
    }
        
    for (auto [num, vec] : mp) {
        if (vec.size() < 2) continue;

        sort(vec.begin(), vec.end());

        int idx = vec.back();
        for (int i=0 ; i<vec.size()-1 ; ++i) {
            if (idx-vec[i] > 1)
                res = max(res, vec[i]);
        }
    }

    mp.clear();
 
    cout << res << '\n';
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
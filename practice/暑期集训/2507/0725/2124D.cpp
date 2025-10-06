//https://codeforces.com/problemset/problem/2124/D
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
    int n, k;
    cin >> n >> k;

    vector<int> tmpa;
    vector<int> b;

    for (int i=0 ; i<n ; ++i) {
        int tmp;
        cin >> tmp;

        tmpa.push_back(tmp);
        b.push_back(tmp);
    }

    sort(b.begin(), b.end());
    int num = b[k-1];

    vector<int> a;

    for (int i=0 ; i<tmpa.size() ; ++i) 
        if (tmpa[i] <= num) 
            a.push_back(tmpa[i]);

    int maxn = a.size() - k + 1;

    int cnt = 0;

    vector<int>::iterator l = a.begin();
    vector<int>::iterator r = a.end() - 1;

// cout << num << ' ' << maxn << '\n';
// for (int i=0 ; i<a.size() ; ++i) {
//     cout << a[i] << ' ';
// }

// cout << '\n';
    while (l < r) {
        if (*l == *r) 
            ++l, --r;
        else if (*l == num && cnt < maxn)
            ++cnt, ++l;
        else if (*r == num && cnt < maxn)
            ++cnt, --r;
        else {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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
/*
*   /\_/\
*  (= ._.)
*  / >  \>
*/
//https://codeforces.com/problemset/problem/2103/C

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

    vector<int> a(n + 1);
    vector<int> p(n + 1, 0);
    vector<int> s(n + 2, 0);

    for (int i=1 ; i<=n ; ++i) {
        cin >> a[i];
        p[i] = p[i - 1];

        if (a[i] <= k) ++p[i];
    }

    for (int i=n ; i>0 ; --i) {
        s[i] = s[i + 1];
        if (a[i] <= k) ++s[i];
    }

    auto cal = [](int x) -> int {
        return ((x + 1) >> 1);
    };

    int l = 1;
    for (int l=1 ; l<=n - 2 ; ++l) {
        if (p[l] >= cal(l)) {
            for (int r=l+1 ; r<n ; ++r) {
                if (p[r] - p[l] >= cal(r-l) || p[n] - p[r] >= cal(n-r)) {
                    cout << "YES\n";
// cout << l << ' ' << r << '\n';
                    return;
                }
            }
        }
    }

    for (int r=n-1 ; r>=2 ; --r){
        if (s[r+1] >= cal(n-r)) {
            for (int l=r-1 ; l>=1 ; --l) {
                if (s[l+1] - s[r+1] >= cal(r-l) || s[1] - s[l+1] >= cal(l)) {
                    cout << "YES\n";
// cout << l << ' ' << r << '\n';
                    return;
                }
            }
        }
    }


    cout << "NO\n";
    // cout << l << ' ' << r << '\n';
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--) {
        solve();
        // cout << "--------------" << '\n';
    }

    return 0;
}
/*
    for(int l=1 ; l<=n-2 ; l++) {
        if(s[l] >= cal(l)){
            for(int r=l+1;r<n;r++){
                if(s[r]-s[l]>=cal(r-l)||s[n]-s[r]>=cal(n-r)){
                    cout<<"YES"<<'\n';
                    return ;
                }
            }
        }
    }

    for (int i=1 ; i<=n ; ++i) cout << p[i] << ' ';
    cout << '\n';
    for (int i=1 ; i<=n ; ++i) cout << s[i] << ' ';
    cout << '\n';


  /\_/\
 (= ._.)
 / >  \>

*/
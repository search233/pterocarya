//https://codeforces.com/problemset/problem/2112/B
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

void solve() {

    int n; cin >> n;
    vector<int> a;
    int tag = 0;
    for(int i=0 ; i<n ; ++i) {
        int num;
        cin >> num;
        a.push_back(num);

        if(i>0 && abs(a[i]-a[i-1])<=1) 
            tag = 1;
    }
    
    if (tag) {
        cout << 0 << '\n';
        return;
    }

    for (int i=1 ; i<n-1 ; ++i) {     
        if ((a[i-1]<a[i] && a[i]>a[i+1]) || (a[i-1]>a[i] && a[i]<a[i+1])) {
            cout << 1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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
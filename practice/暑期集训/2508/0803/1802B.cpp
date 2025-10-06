//https://codeforces.com/problemset/problem/1802/B
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
const ll INF = LLONG_MAX;


void solve() {
    int n; cin >> n;
    vector<int> b(n);

    int cnt[2] = {0}; // zh ko
    for (int i=0 ; i<n ; ++i) {
        cin >> b[i];
    }

    int tag = 0;
    int tcnt = 0;
    int pigcnt = 0;
    for (int i=0 ; i<n ; ++i) {
        if (b[i] == 1 ) {
            ++tcnt;
            ++pigcnt;
            tag = 1;
        }
        else if (tag){

            tag = 0;
            
            if (cnt[1] < tcnt) 
                cnt[1] = tcnt;

            tcnt = 0;

            int tres = cnt[0] + cnt[1];
            cnt[0] = (pigcnt >> 1) + 1;
            cnt[1] = tres - cnt[0];
        } 
    }

    if (tcnt) {
            if (cnt[1] < tcnt) 
                cnt[1] = tcnt;

            tcnt = 0;

            int tres = cnt[0] + cnt[1];
            cnt[0] = (pigcnt >> 1) + 1;
            cnt[1] = tres - cnt[0];        
    }

    cout << cnt[0] + cnt[1] << '\n';
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



  /\_/\
 (= ._.)
 / >  \>

*/
//https://codeforces.com/problemset/problem/ /
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
    int n, c; 
    cin >> n >> c;

    vector<int> a;
    for (int i=0 ; i<n ; ++i) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    int res = 0;
    vector<int> tag;

    for (int i=a.size() - 1 ; i>=0 ; --i) {
        if (a[i] > c) ++res;
        else {
            int tmp = c / a[i];

            int tcnt = 0;
            while (tmp) {
                tmp >>= 1;
                ++tcnt;
            }

            tag.push_back(tcnt);
            // cout << tcnt << ' ';
        }
    }

    sort(tag.begin(), tag.end());

    for (int i=0 ; i<tag.size() ; ++i) {
        if (tag[i] <= i) {
            ++res;
            tag.erase(tag.begin() + i);
            --i;
            // cout << tag[i] << ' ';
        }

        
    }
    // cout << '\n';

    cout << res << '\n';
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
*   /\_/\
*  (= ._.)
*  / >  \>
*/
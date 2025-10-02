//https://codeforces.com/problemset/problem/2125/A
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

int a[N];

void solve() {
    string s;
    cin >> s;

    deque<char> dq;
    for (int i=0  ; i<s.length() ; ++i) {
        if (s[i] == 'T') dq.push_front(s[i]);
        else dq.push_back(s[i]);
    }

    while(!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
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

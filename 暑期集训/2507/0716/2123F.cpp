//https://codeforces.com/problemset/problem/2123/F
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

int tag[N];
int prime[N];
bool numlist[N];
deque<int> ans[N];

void get_prime() {
    int cnt = 0;
    for (int i=2 ; i<=N ; ++i) {
        if (!numlist[i]) prime[cnt++] = i;

        for (int j=0 ; prime[j]<=N/i ; ++j) {
            numlist[prime[j]*i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

void solve() {
    int n; cin >> n;

    tag[1] = 1;
    ans[1].push_back(1);

    for (int i=2 ; i<=n ; ++i) {
        int tmp = i;
        
        for (int j : prime) {
            while (tmp % j == 0) 
                tmp /= j;
            
            if (tmp == 1) {
                tag[i] = j;
                ans[j].push_back(i);
                break;
            }
        }
    }

    for (int i=1 ; i<=n ; ++i) {
        if (ans[tag[i]].front() == tag[i]) {
            ans[tag[i]].pop_front();
            ans[tag[i]].push_back(tag[i]);
        }

        cout << ans[tag[i]].front() << ' ';
        ans[tag[i]].pop_front();
        // cout << prime[i] << ' ';
    }

    cout << '\n';
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    get_prime();

    while (_T--)
        solve();

    return 0;
}
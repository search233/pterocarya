//https://codeforces.com/problemset/problem/2145/C2

#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

vector<int> primes;

void init(int n) {
    vector<int> vis(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!vis[i])
           primes.push_back(i);

        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}


void solve() {
    int n; cin >> n;

    vector<int> a(n + 1);
    vector<ll> b(n + 1);

    for (int i=0 ; i<n ; ++i) {
        cin >> a[i + 1];
    }

    for (int i=0 ; i<n ; ++i) {
        cin >> b[i + 1];
    }

    map<int, int> mp;

    for (int i=0 ; i<n ; ++i) {
        int pos = 0;
        int num = a[i + 1];

        while (num > 1 && primes[pos] <= sqrt(a[i + 1])) {

            if (num % primes[pos] == 0) {
                ++mp[primes[pos]];
            }
            
            while (num % primes[pos] == 0) {
                num /= primes[pos];
            }

            ++pos;
        }

        if (num != 1) ++mp[num];
    }

    for (auto [num, cnt] : mp) {
        if (cnt > 1) {
            cout << "0\n";
            return;
        }
    }

    ll ans = LLONG_MAX;

    for (int i=0 ; i<n ; ++i) {
        int num = a[i + 1] + 1;
        int pos = 0;

        while (num > 1 && primes[pos] <= sqrt(a[i + 1] + 1)) {

            if (num % primes[pos] == 0) {
                if (mp.count(primes[pos])) {
                    ans = min(ans, b[i + 1]);
                    continue;
                }
            }
            
            while (num % primes[pos] == 0) {
                num /= primes[pos];
            }

            ++pos;
        }

        if (mp.count(num)) {
            ans = min(ans, b[i + 1]);
            continue;
        }
    }

    for (int i=0 ; i<n ; ++i) {
        
    }
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    init(N);

    while (_--) {
        solve();
        // cout << "-----------\n
    }

    return 0;
}
/*
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │              
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐    
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │    
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
│Ctrl │Win │Alt │         Space         │Alt │ Fn │Menu│Ctrl│ │ ← │ ↓ │ → │
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

*/
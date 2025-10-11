//https://codeforces.com/problemset/problem/2155/C

#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  676767677;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);


void solve() {
    int n; cin >> n;

    vector<int> a(n);

    for (int i=0 ; i<n ; ++i) {
        cin >> a[i];
    }

    vector<arr2> tag(n + 1);
    vector<int> sum(n);

    for (int i=1 ; i<n ; ++i) {
        if (a[i] == a[i - 1]) {
            if (tag[i][1]) tag[i - 1][0] = 1;
            else if (tag[i][0]) tag[i - 1][1] = 1;
        }
        else {
            if (a[i] - a[i - 1] == 1) {
                tag[i - 1][0] = tag[i][0] = 1;
            }
            else if (a[i - 1] - a[i] == 1) {
                tag[i - 1][1] = tag[i][1] = 1;
            }
            else {
                cout << "01\n";
                return;
            }
        }
    }

    int cnt = (tag[n - 1][1] ? 1 : 0);
    sum[n - 1] = 1;

    for (int i=n-2 ; i>=0 ; --i) {
        if (a[i] == a[i + 1]) {
            if (tag[i + 1][1]) tag[i][0] = 1;
            if (tag[i + 1][0]) tag[i][1] = 1;
        }

        if (tag[i][1] && tag[i][0]) {
            cout << "02\n";
            return;
        }

        sum[i] = 1 + cnt; 
        // cout << sum[i] << '\n';
        if (tag[i][1]) ++cnt;
    }

    for (int i=0 ; i<n ; ++i) {
        cout << sum[i] << " \n"[i == n - 1];
    }
return;

    cnt = (tag[0][0] ? 1 : 0);
    if (sum[0] != a[0]) {
        cout << "03\n";
        return;
    }

    for (int i=1 ; i<n ; ++i) {
        sum[i] += cnt;
        if (tag[i][0]) ++cnt;

        if (sum[i] != a[i]) {
            cout << "04\n";
            return;
        }
    }

    if (tag[0][0] || tag[0][1]) {
        cout << "1\n";
    }
    else {
        cout << "2\n";
    }
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        cout << "-----------" << '\n';
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
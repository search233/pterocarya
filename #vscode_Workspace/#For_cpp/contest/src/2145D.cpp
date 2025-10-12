//https://codeforces.com/problemset/problem/2145/D

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


void solve() {
    int n, k;
    cin >> n >> k;

    if (k < n - 1 && k) {
        cout << 0 << '\n';
        return;
    }

    vector<int> ans(n + 1);

    for (int i=1 ; i<=n ; ++i) ans[i] = i;

    int left = n * (n - 1) / 2 - k;

    vector<int> dep;
    //-1: unknown; 
    //0 : cant;
    //1 : can;
    vector<vector<int>> memo(n * (n - 1) / 2 + 1, vector<int> (n + 2, -1));

    auto dfs = [&](auto& dfs, int sum1, int sum2) -> bool {

        if (memo[sum1][sum2] != -1) return memo[sum1][sum2];

        if (sum1 == left) return 1;

        for (int i=2 ; i<=n ; ++i) {

            if (sum1 + i * (i - 1) / 2 > left || sum2 + i > n) {
                return memo[sum1][sum2] = 0;
            }

            dep.push_back(i);
            if (dfs(dfs, sum1 + i * (i - 1) / 2, sum2 + i)) return 1;
            dep.pop_back();
        }

        return memo[sum1][sum2] = 0;
    };

    if (!dfs(dfs, 0, 0)) {
        cout << "0\n";
        return;
    }

    int pos = 1;
    for (auto& i : dep) {
        reverse(ans.begin() + pos, ans.begin() + pos + i);

        pos += i;
    }

    for (int i=n ; i>0 ; --i) cout << ans[i] << " \n"[i == 1];
} 

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------" << '\n';
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
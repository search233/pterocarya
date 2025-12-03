//https://codeforces.com/problemset/problem/2132/D

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

void solve() {
    ll n; cin >> n;
    ll ans = 0;

    ll num = 0;
    ll cnt = 1;
    while (1) {
        ll tmp = 9;
        for (int i=1 ; i<cnt ; ++i)
            tmp *= 10;
        
        if (n < tmp * cnt) {
            num += n / cnt;
            cnt = n % cnt;

            string ts = to_string(num + 1);
            for (int i=0 ; i<cnt ; ++i)
                ans += ts[i] - '0';

            break;

        } else {
            n -= tmp * cnt;
            num += tmp;
            ++cnt;
        }       
    }

    string s = to_string(num);

    // cout << s << ' ' << ans << '\n';
    // return;

    ll memo[20][2][2][20];    

    auto dfs = [&](auto& dfs, int pos, bool lim, bool zero, ll sum, int num) -> ll {
        if (pos == s.length()) return sum;
   
        ll& res = memo[pos][lim][zero][sum];
        if (~res) return res;
        else res = 0;
        //记忆化搜索，避免重复计数
   
        int upbd = 9;
        if (lim) upbd = s[pos] - '0';
        //确定当前上界(upper_bound
   
        for (int i=0 ; i<=upbd ; ++i) {
            // if (!zero) continue;
            //根据题意加入限制
   
            res += dfs(dfs, pos + 1, lim && (i == upbd), (zero && !i), sum + (i==num), num);
            // cout << pos << ' ' << pnum <<  i << ' ' << res << '\n';
        }
   
        return res;
    };

    for (int i=1 ; i<10 ; ++i) {
        memset(memo, -1, sizeof(memo));
        // cout <<  dfs(dfs, 0, 1, 1, 0, i) << ' ';
        ans += dfs(dfs, 0, 1, 1, 0, i) * i;
    }

    cout << ans << '\n';
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
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
│ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

 

 // int memo[20][2][10][2];
 // memset(memo, -1, sizeof(memo));
 //记忆化数组

 auto dfs = [&](auto& dfs, int pos, bool lim, int pnum, bool zero) -> vector<int> {
     if (pos == s.length()) return 1;

     // int& res = memo[pos][lim][pnum][zero];
     // if (~res) return res;
     // else res = 0;
     //记忆化搜索，避免重复计数
     vector<int> res(10, 0);

     int upbd = 9;
     if (lim) upbd = s[pos] - '0';
     //确定当前上界(upper_bound

     for (int i=0 ; i<=upbd ; ++i) {
         if (!zero) continue;
         //根据题意加入限制

         vector<int> tmp = dfs(dfs, pos + 1, lim && (i == upbd), i, (zero && !i));
         for (int i=0 ; i<10 ; ++i) res[i] += tmp[1];
         // cout << pos << ' ' << pnum <<  i << ' ' << res << '\n';
     }

     return res;
 };

*/
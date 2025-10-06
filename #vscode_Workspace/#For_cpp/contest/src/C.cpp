//https://codeforces.com/problemset/problem/ /
//https://atcoder.jp/contests/ /tasks/ /
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>
#define int long long


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
    int n; cin >> n;

    string s; cin >> s;
    vector<arr2> arr;

    int cnt = 0;
    for (int i=0 ; i<n ; ++i) {
        if (s[i] == 'a') ++cnt;
        if (arr.empty() || s[i] - 'a' != arr.back()[0]) arr.push_back({s[i] - 'a', 1});
        else ++arr.back()[1];
    }

    // for (auto [ch, cnt] : arr) {
    //     cout << (char)(ch + 'a') << ' ' << cnt << '\n';
    // }
    if (cnt * 2 == n) {
        cout << "0\n";
        return;
    }

    int dif = n - 2 * cnt;

    int ans = INT_MAX;

    if (dif > 0) { //b
        for (int i=0 ; i<arr.size() ; ++i) {
            if (arr[i][0] == 1) {
                if (arr[i][1] >= dif) {
                    cout << (dif != n ? dif : -1) << '\n';
                    return;
                }
                else  {
                    int pos = i, sum = 0, temp = arr[i][1];
                    while (pos < arr.size() - 2 && arr[pos+2][1] > arr[pos+1][1]){
                        sum += arr[pos+1][1] * 2;
                        temp += arr[pos+2][1] - arr[pos+1][1];

                        if (temp <= arr[pos+2][1]) break;
                        if (temp >= dif) {
                            ans = min(ans, sum + dif);
                        }
                        pos += 2;
                    }
                }
            }            
        }
    }
    else {
        dif = -dif;
        for (int i=0 ; i<arr.size() ; ++i) {
            if (arr[i][0] == 0) {
                if (arr[i][1] >= dif) {
                    cout << (dif != n ? dif : -1) << '\n';
                    return;
                }
                else  {
                    int pos = i, sum = 0, temp = arr[i][1];
                    while (pos < arr.size() - 2 && arr[pos+2][1] > arr[pos+1][1]){
                        sum += arr[pos+1][1] * 2;
                        temp += arr[pos+2][1] - arr[pos+1][1];

                        if (temp <= arr[pos+2][1]) break;
                        if (temp >= dif) {
                            ans = min(ans, sum + dif);
                        }
                        pos += 2;
                    }
                }
            }            
        }
    }

    // cout << n << '\n';

    if (ans == n) cout << -1 << '\n';
    else cout << ans << '\n';

} 

signed main() {
    
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
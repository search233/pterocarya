//https://www.luogu.com.cn/problem/P1616

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e7 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

ll a[10010]; //t
ll b[10010]; //w
ll dp[M];

void solve()
{
    int t, m;
    cin >> t >> m;

    for (int i=0 ; i<m ; ++i) 
        cin >> a[i] >> b[i];
 
    for (int i=0 ; i<m ; ++i) {
        for (int j=a[i] ; j<=t ; ++j) {
                dp[j] = max(dp[j], b[i]+dp[j-a[i]]);
        }
    }

    cout << dp[t];
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--)
    {
        solve();
    }

    return 0;
}

/*
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永远AC
//
//
//
*/
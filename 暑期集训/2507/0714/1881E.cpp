//https://codeforces.com/problemset/problem/1881/E
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

int dp[N];
int num[N];

void solve()
{
    int n; cin >> n;

    for (int i=1 ; i<=n ; ++i) {
        cin >> num[i];
        dp[i] = 0;
    }

    dp[n] = 1;
    for (int i=n-1 ; i>0 ; --i) {

        if ( i+num[i] > n )
            dp[i] = dp[i+1] + 1;

        else if ( i+num[i] == n )
            dp[i] = 0;

        else 
            dp[i] = min(dp[i+num[i]+1], dp[i+1] + 1);
        
    }
    
    int res = INT_MAX;
    for (int i=1 ; i<=n ; ++i)
        res = min(res, dp[i] + i-1);
    
    cout << res << '\n';
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _T = 1;
    cin >> _T;
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
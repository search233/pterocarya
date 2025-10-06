//https://www.luogu.com.cn/problem/P1216

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

int graph[1009][1009];

void solve()
{
    int n; cin >> n;

    for (int i=1 ; i<=n ; ++i) {
        for (int j=1 ; j<=i ; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int i=n-1 ; i>0 ; --i) {
        for (int j=1 ; j<=i ; ++j) {
            graph[i][j] += max(graph[i+1][j+1], graph[i+1][j]);
        }
    }
    // for (int i=1 ; i<=n ; ++i) {
    //     for (int j=1 ; j<=i ; ++j) {
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << graph[1][1];
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
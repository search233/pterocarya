//https://www.luogu.com.cn/problem/P1049

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

int w[35];
int vol[20010];

void solve()
{
    int V, n; cin >> V >> n;

    for (int i=1 ; i<=n ; ++i)
        cin >> w[i];
    
        // for (int j=0 ; j<=V ; ++j) 
        //     printf("%02d ", j);

        // cout << '\n';


    for (int i=1 ; i<=n ; ++i) {
        for (int j=V ; j>=w[i] ; --j) {
            vol[j] = max(vol[j], w[i]+vol[j-w[i]]);
        }
        // for (int j=0 ; j<=V ; ++j) 
        //     printf("%02d ", vol[j]);
    
        // cout << '\n';
    }

    cout << V-vol[V];
     
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
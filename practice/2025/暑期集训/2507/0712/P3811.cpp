//https://codeforces.com/problemset/problem/
//https://www.luogu.com.cn/problem/3811

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

void exgcd(int a, int b, int& x, int& y) {
    if(!b) {
        x = 1;
        y = 0;
    }else {
        exgcd(b, a%b, x, y);
        int t=x;
        x = y;
        y = t - (a/b)*y;
    }
}

void solve()
{
    int n, p;
    cin >> n >> p;

    for(int i=1 ; i<=n ; ++i) {
        int x=1, y=0;
        exgcd(i,p,x,y);
        x = (x%p + p) % p;
        cout << x << '\n';
    }
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
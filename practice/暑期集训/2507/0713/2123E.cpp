//https://codeforces.com/problemset/problem/2123/E

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;

int res[200010];

void solve()
{
    map<int,int> mp;
    int n; cin >> n;

    for(int i=0 ; i<n ; ++i) {
        int num; cin >> num;
        ++mp[num];
        res[i] = 0;
    }
    res[n]=0;

    int tag=0;
    for (auto [num, times] : mp) {
        if (tag != num) 
            break;

        ++tag;
        ++res[times];
        --res[n-num+1];
        // cout << num << ' ' << times << '\n';
    }

    res[0] = 1;
    --res[n-tag+1];
    cout << res[0];

    for (int i=1 ; i<=n ; ++i) {
        res[i] += res[i-1];
        cout << ' ' << res[i];
    }
    cout << '\n';
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
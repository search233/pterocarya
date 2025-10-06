//https://codeforces.com/problemset/problem/2115/A
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

int d[5001];

void solve()
{
    int n; cin >> n;

    int g;
    vector<int> num(n);

    for (int i=0 ; i<n ; ++i) {
        cin >> num[i];
        if( i==0 ) g = num[0];
        else g = __gcd(g, num[i]);
    } 
    
    
    
    int tcnt = 0;
       for (int i=0 ; i<n ; ++i) {
        num[i] /= g;
        if( num[i]==1 ) ++tcnt;
    }

        
    if( tcnt ) cout << n - tcnt << '\n';
    else {
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(),num.end()),num.end());

        for (int i=1 ; i<=5000 ; ++i)
            d[i] = INT_MAX;

        queue<int> qu;

        for (int i=0 ; i<num.size() ; ++i) {
            qu.push(num[i]);
            d[num[i]] = 0;
        }

        while(!qu.empty()) {
            int x = qu.front();
            qu.pop();

            if( x==1 ) break;
            else {
                for(auto y : num) {
                    int gc = __gcd(y,x);
                    if ( d[gc] > d[x]+1 ) {
                        d[gc] = d[x]+1;
                        qu.push(gc);
                    }
                }
            }
        }

        cout << d[1]+n-1 << '\n';
    }
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
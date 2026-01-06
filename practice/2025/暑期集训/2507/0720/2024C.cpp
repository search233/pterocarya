//https://codeforces.com/problemset/problem/2024/C
//https://www.luogu.com.cn/problem/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)1e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;

struct Node{
    int a1;
    int a2;
}a[N];

int cmp(Node a, Node b) { 
    if (max(a.a1, a.a2) != max(b.a1, b.a2))
        return  max(a.a1, a.a2) < max(b.a1, b.a2);
    else 
        return min(a.a1, a.a2) < min(b.a1, b.a2);
 }

void solve() {
    int n;
    cin >> n;

    for (int i=0 ; i<n ; ++i)
        cin >> a[i].a1 >> a[i].a2;

        sort(a, a+n, cmp);

        for (int i=0 ; i<n ; ++i) 
            cout << a[i].a1 << ' ' << a[i].a2 << ' ';

        cout << '\n';
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _T = 1;
    cin >> _T;

    while (_T--)
        solve();

    return 0;
}

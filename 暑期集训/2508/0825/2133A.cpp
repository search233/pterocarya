//https://codeforces.com/problemset/problem/2133/A

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
const ll INF = LLONG_MAX;


void solve() {
    int n; cin >> n;
    set<int> s;

    for (int i=0 ; i<n ; ++i) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    } 


    if (s.size() < n) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}

// 4 5
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1


// 3 6
// 350 360 370 380 390 400
// 240 240 240 240 240 240
// 480 480 520 600 600 600 

// 3 5
// 1 1 1 1 1
// 5 5 5 5 5 
// 25 25 25 25 25
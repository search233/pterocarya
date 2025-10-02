#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

    int m = rand() % 6 + 1;// n 从 1 到 100
    int n = rand() % 6 + 1;// n 从 1 到 100

    cout << n << ' ' << m << '\n';
    for (int i=1 ; i<=n ; ++i) {
        int num = rand() % 9 + 1;
        cout << num << " \n"[i == n];
    }

    for (int i=1 ; i<=m ; ++i) {
        int num = rand() % 9 + 1;
        cout << num << " \n"[i == m];
    }



    // cout << (n & 1 ? n + 1 : n) << '\n';

}

int main()
{
    srand(time(0));

    int t = rand() % 5 + 1; 
    // int t = 50;
    cout << t << '\n';

    while(t--) {
        solve();
    }

	return 0;
}

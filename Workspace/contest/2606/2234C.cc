#include <bits/stdc++.h>
#include <cassert>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void solve() {
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a) {
        cin >> i;
    }

    auto cal = [&](int x) -> ll {
        vector<int> tmp;
        for(int i = 1;i<n;i++){
            tmp.push_back(a[(i+x)%n]);
        }
        tmp.push_back(a[x]);
        
        ll res = 0;
        vector<int> maxn(n + 1,0);
        for(int i = n-2; i>=0 ;i--){
            maxn[i] = max(maxn[(i + 1 + n) % n] , tmp[i]);
        }

        int cur = n - 1;
        while(max(maxn[cur] , maxn[(cur + 1) % n]) > tmp[cur]){
            maxn[(cur + 1) % n] = max(maxn[cur] , tmp[cur]);
            cur = (cur + 1) % n;
        }
        
        for(int i = 0;i < n; i++){
            res += maxn[i];
        }
        return res;
    };

    for (int i = 0; i < n; ++i) {
        // cal(i);
        cout << cal(i);
        cout << " \n"[i == n - 1];
    }
}

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------\n";
    }

    return 0;
}
/*
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░
*/
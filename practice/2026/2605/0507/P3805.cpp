#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

struct manacher {
    vector<char> s;
    int n;

    manacher(string& ss) {
        n = ss.size();
        int k = 0;
        s.push_back('$');
        s.push_back('#');

        for (int i = 0; i < n; i++) {
            s.push_back(ss[i]);
            s.push_back('#');
        }
        s.push_back('&');
        n = s.size() - 1;
    }

    vector<int> run() {
        int r = 0, c;
        vector<int> p(n);
        for (int i = 1; i < n; ++i) {
            if (i < r) p[i] = min(r - i, p[2 * c - i]);
            else p[i] = 1;

            while (s[i + p[i]] == s[i - p[i]]) p[i]++;
            if (i + p[i] > r) {
                r = i + p[i];
                c = i;
            }
        }
        return p;
    }
};

void solve() {
    string s; cin >> s;
    manacher m(s);
    vector<int> p(m.run());

    int mx = 0;
    for (auto& i : p) {
        mx = max(mx, i);
    }
    cout << mx - 1;
}

int main() {
    
    __BUFF__

    int _ = 1;
    // cin >> _;

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
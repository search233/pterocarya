#include <bits/stdc++.h>
#include <bits/extc++.h>

#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);


struct MyHash {
    // 随机盐
    static inline const uint64_t SEED = 
        std::chrono::steady_clock::now().time_since_epoch().count();

    // WyHash 搅拌机
    static uint64_t mix(uint64_t x) {
        x ^= SEED;
        unsigned __int128 m = (unsigned __int128)x * 0xbf58476d1ce4e5b9ULL;
        uint64_t a = (m >> 64) ^ m;
        m = (unsigned __int128)a * 0x94d049bb133111ebULL;
        return (m >> 64) ^ m;
    }
    
    // ======== 对应的重载 ========
    size_t operator()(uint64_t a) const noexcept {
        return mix(a);
    }

    // size_t operator()(const arr3& a) const noexcept {
    //     auto [x, y, z] = a;
    //     uint64_t res = mix(x);
    //     res = mix(res ^ y); // 把第二维的 y 揉进第一维的结果里
    //     res = mix(res ^ z); // 把第三维的 z 揉进去
    //     return res;
    // }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);

    unordered_map<int, arr2, MyHash> mp;
    mp.reserve(n * 100);

    auto cal = [&](int x) -> void {
        if (x == 1) {
            ++mp[2][0];
            ++mp[2][1];
        }
        
        int cnt = 0;
        while (x != 1) {
            auto& mm = mp[x];

            ++mm[0];
            mm[1] += cnt;

            if (x & 1) ++x;
            else x >>= 1;
            ++cnt;
        }

        ++mp[1][0];
        mp[1][1] += cnt;
    };

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cal(a[i]);
    }

    int mn = 1e9;
    for (auto [x, y] : mp) {
        if (y[0] == n) {
            mn = min(mn, y[1]);
        }
    } 

    cout << mn << '\n';
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
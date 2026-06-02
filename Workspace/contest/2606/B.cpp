#include <bits/stdc++.h>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

ll cost[64][64];

const ll INF = 1e18; // 足够大的边界值，防止 long long 溢出

struct Op {
    // 广义加法：取最大值
    static inline ll add(ll a, ll b) { 
        return max(a, b); 
    }
    
    // 广义乘法：变为加法
    static inline ll mul(ll a, ll b) { 
        if (a == -INF || b == -INF) return -INF; // 有效性剪枝与防溢出
        return a + b; 
    }
    
    static inline const ll ZERO = -INF; // max(广义加法) 的零元：max(-INF, x) = x
    static inline const ll ONE  = 0;    // + （广义乘法）的单位元：0 + x = x
};


// ==================== 2. 矩阵通用模板 (无需修改) ====================
struct Mat {
    int r, c;
    vector<vector<ll>> v;

    // 构造函数：默认使用 Op::ZERO 初始化
    Mat(int row, int col) : r(row), c(col) {
        v.assign(r, vector<ll>(c, Op::ZERO));
    }

    // 重载乘法运算符
    Mat operator * (const Mat& b) const {
        Mat res(r, b.c); // 结果矩阵的大小为 r * b.c
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < c; ++k) {
                // 剪枝：如果当前左矩阵元素为零元，则跳过循环（对标准乘法和布尔乘法大幅加速）
                if (v[i][k] == Op::ZERO) continue; 
                
                for (int j = 0; j < b.c; ++j) {
                    ll next_val = Op::mul(v[i][k], b.v[k][j]);
                    res.v[i][j] = Op::add(res.v[i][j], next_val);
                }
            }
        }
        return res;
    }
};

// 矩阵快速幂
Mat qpow(Mat a, ll p) {
    Mat res(a.r, a.c);
    // 初始化广义单位矩阵
    for (int i = 0; i < a.r; ++i) {
        res.v[i][i] = Op::ONE;
    }

    while (p > 0) {
        if (p & 1) res = res * a;
        a = a * a;
        p >>= 1;
    }
    return res;
}

void solve() {
    int n, m, k, r;
    cin >> n >> m >> k >> r;

    vector<arr2> b(n);
    for (auto& [a, c] : b) {
        cin >> a >> c;
    }

    for (int s1 = 0; s1 < (1 << n); ++s1) {
        for (int s2 = 0; s2 < (1 << n); ++s2) {
            cost[s1][s2] = 0;
            for (int l = 0; l < n; ++l) {
                if ((s2 >> l) & 1) {
                    cost[s1][s2] += b[l][1] + k * ((s1 >> l) & 1);
                }
            }
        }
    }

    auto cal = [&](int s) -> ll {
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += b[i][0] * ((s >> i) & 1);
        }
        return ans;
    };

    Mat s((1 << n), (1 << n));

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if (cost[i][j] <= m)
                s.v[i][j] = cal(j);
        }
    }
    Mat ans(1, (1 << n));
    ans.v[0][0] = Op::ONE;

    ans = ans * qpow(s, r);

    ll mx = 0;
    for (auto i : ans.v[0]) {
        mx = max(i, mx);
    }

    cout << mx << '\n';
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
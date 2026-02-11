#include <bits/stdc++.h>
using namespace std;

static const int MAX_A = 26;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;

// 生成 [L, R] 范围内的随机整数
int rnd(int L, int R)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(L, R);          // 闭区间
    return dis(gen);
}

void solve() {
    // int n = rnd(3, 9);
    // int m = rnd(1, 10);

    int n = rnd (5, 10);
    int m = rnd(1, n + 2);
    cout << n << ' ' << m << '\n';

    set<arr2> st;
    for (int i = 0; i < m; ++i) {
        int u = rnd(1, n);
        int v = rnd(1, n);

        while (u >= v || st.count({u, v})) {
            u = rnd(1, n);
            v = rnd(1, n);
        }

        st.insert({u, v});
        cout << u << ' ' << v << '\n';
    }
}

int main() {
    int _= 1;
    // cout << _ << '\n';

    solve();

    return 0;
}

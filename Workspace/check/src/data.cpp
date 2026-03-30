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
    // 1. 生成灯泡数量 n (1 <= n <= 100)
    int n = 12;
    cout << n << '\n';

    // 2. 生成 1 到 n 的排列
    vector<int> a(n);
    iota(a.begin(), a.end(), 1); // 填充 1, 2, 3... n

    // 3. 随机决定有多少个灯泡掉落（即变成 0 的数量，0 到 n 之间）
    int zero_count = rnd(0, n);

    // 4. 将数组打乱，以便随机挑选被替换为 0 的灯泡
    for (int i = n - 1; i > 0; --i) {
        swap(a[i], a[rnd(0, i)]);
    }

    // 5. 将前 zero_count 个元素变成 0
    for (int i = 0; i < zero_count; ++i) {
        a[i] = 0;
    }

    // 6. 再次打乱数组，让 0 和剩下的非零数字在位置上完全随机分布
    for (int i = n - 1; i > 0; --i) {
        swap(a[i], a[rnd(0, i)]);
    }

    // 7. 输出最终生成的数据
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}

int main() {
    int _= 1;
    // cout << _ << '\n';

    while (_--)
        solve();

    return 0;
}

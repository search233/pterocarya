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
    int num = rnd(1, 100);
    cout << num << '\n';
}

int main() {
    int _= 1;
    cout << _ << '\n';

    solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

static const int MAX_A = 26;

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

    int n = 4;

    cout << n << '\n';
    for (int j = 0; j < 2; ++j) {
        for (int i = 1; i <= n; ++i) {
            int num = rnd(1, n * 2);
            cout << num << " \n"[i == n];
        }
    }
}

int main() {
    int _= 1;
    cout << _ << '\n';

    solve();

    return 0;
}

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

    int n = 5;
    int x = rnd(1, 100);
    int y = rnd(1, 100);

    cout << n << ' ' << x << ' ' << y << '\n';

    for (int i = 0; i < n; ++i) {
        char ch  = rnd(0, 1) + '0';
        cout << ch;
    }

    cout << '\n';

    for (int i = 0; i< n ; ++i) {
        int p  =  rnd(1, 10);
        cout << p << " \n"[i == n - 1];
    }
}

int main() {
    int _= 1;
    cout << _ << '\n';

    solve();

    return 0;
}

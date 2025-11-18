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
    int n = rnd(3, 9);
    int m = rnd(1, 10);

    cout << n << ' ' << m << '\n';
    for (int i=0 ; i<n ; ++i) {
        int a = rnd(0, 100);
        cout << a << " \n"[i == n-1];
    }
        for (int i=0 ; i<m ; ++i) {
        int b = rnd(0, 100);
        cout << b << " \n"[i == m-1];
    }
        for (int i=0 ; i<m ; ++i) {
        int c = rnd(0, 100);
        cout << c << " \n"[i == m-1];
    }
}

int main() {
    int _= 1;
    cout << _ << '\n';

    solve();

    return 0;
}

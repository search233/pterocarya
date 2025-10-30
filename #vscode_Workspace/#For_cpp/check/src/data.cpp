#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = (int)2e4;

// 1. 生成 [min, max) 范围内的随机整数
int rand_int_half_open(int min, int max)
{
    static std::random_device rd;                              // 非确定性种子
    static std::mt19937 gen(rd());                             // 32 位梅森旋转算法引擎
    std::uniform_int_distribution<int> dis(min, max - 1);      // 半开区间
    return dis(gen);
}

// 2. 生成 [min, max] 范围内的随机整数
int rand_int_closed(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);          // 闭区间
    return dis(gen);
}

void solve() {
    int n = rand_int_closed(2, 9);
    int q = rand_int_closed(1, n);

    cout << n << ' ' << q << '\n';
    for (int i=0 ; i<n ; ++i) {
        int x = rand_int_closed(5, 40);
        int y = rand_int_closed(x, 70);
        int z = rand_int_closed(y, 1000);

        cout << x << ' ' << y << ' ' << z << '\n';
    }

    for (int i=0 ; i<q ; ++i) {
        cout << i + 1 << ' ';
    }
}

int main()
{
    srand(time(0));

    int t = 1;

    // int t = 50;
    // cout << t << '\n';

    // int sumn = N;

    while(t--) {
        solve();
    }

	return 0;
}

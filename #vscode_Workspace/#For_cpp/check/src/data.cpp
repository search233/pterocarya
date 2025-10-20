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

void solve(int& sumn) {

    int n = rand_int_closed(1, sumn - 1);

    sumn -= n;

    vector<ll> p(n);
    iota(p.begin(), p.end(), 1); // p = [1, 2, 3, ..., n]

    random_device rd;  // 从硬件获取随机种子
    mt19937 gen(rd()); // 梅森旋转随机数引擎（高质量随机性）

    shuffle(p.begin(), p.end(), gen);

    ll ans = rand_int_closed(0, 10000000);

    cout << ans << '\n';

    for (int i=0 ; i<n ; ++i) {
        ll plus = rand_int_closed(0, ans);
        p[i] += plus;
        ans -= plus;
    }
}

int main()
{
    srand(time(0));

    int t = rand_int_closed(1, 10000);

    // int t = 50;
    cout << t << '\n';

    int sumn = N;

    while(t--) {
        solve(sumn);
    }

	return 0;
}

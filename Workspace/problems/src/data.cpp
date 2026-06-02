#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;

// 生成 [L, R] 范围内的随机整数
int rnd(int L, int R) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(L, R);          // 闭区间
    return dis(gen);
}

void solve() {
    // 1. 设定 n 和 m 的范围（可根据需求调整，这里配置为中小规模以便测试）
    // 题目最大范围：2 * 10^5
    int n = rnd(2, 100000); 
    int m = rnd(1, 100000); 
    
    std::cout << n << " " << m << "\n";
    
    // 2. 构造一棵树 (n-1 条边)
    // 边的权重范围设定
    int max_w = 200000; 
    
    for (int i = 2; i <= n; ++i) {
        // 随机选择前方的一个节点作为父亲，保证图连通且无环
        int u = rnd(1, i - 1);
        int v = i;
        int w = rnd(1, max_w);
        
        // 随机交换一下 u 和 v 的输出顺序，使数据更自然
        if (rnd(0, 1)) {
            std::swap(u, v);
        }
        std::cout << u << " " << v << " " << w << "\n";
    }
    
    // 3. 构造 m 个询问的 q_i
    for (int i = 1; i <= m; ++i) {
        int q = rnd(1, max_w);
        std::cout << q << (i == m ? "" : " ");
    }
    std::cout << "\n";
}


int main() {
    int _ = 1;
    // cout << _ << '\n';

    while (_--)
        solve();

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 1. 打开牛客网规定的标准文件
    ifstream fin("input");
    ifstream fuser("user_output");
    // 注：本题是构造题，答案不唯一，因此通常不需要读取标准输出 "output"
    
    if (!fin.is_open() || !fuser.is_open()) {
        return 1; // 文件打开失败，直接返回错误
    }

    int _;

    if (!(fin >> _)) {
        return 1;
    }

    auto ck = [&]() -> bool {
        // 2. 读取输入数据 X 和 d
        long long X, d;
        if (!(fin >> X >> d)) {
            return 1; 
        }
    
        // 3. 读取选手输出的第一个数 (n 或 -1)
        int n;
        if (!(fuser >> n)) {
            return 1; // 选手没有输出或者输出格式错误
        }
    
        // 因为本题在数学上对任意合法的 X, d 永远有解
        // 如果选手输出了 -1，或者 n 的范围不合法 (1 <= n <= 10000)，判定错误
        if (n <= 0 || n > 10000) {
            return 1; 
        }
    
        // 4. 读取选手的整个数组并检查元素合法性
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            if (!(fuser >> a[i])) {
                return 1; // 选手输出的元素个数不足 n 个
            }
            // 检查元素数值范围：1 <= a[i] < 10^18
            if (a[i] < 1 || a[i] >= 1000000000000000000LL) {
                return 1; 
            }
        }
    
        // 5. 核心逻辑：排序并使用双指针计算合法子序列数量
        sort(a.begin(), a.end());
    
        long long total_subsequences = 0;
        int r = 0;
    
        for (int l = 0; l < n; ++l) {
            // 扩展右指针，直到不满足 a[r] - a[l] < d
            while (r < n && a[r] - a[l] < d) {
                r++;
            }
            
            // 统计以 a[l] 为最小值的合法子序列数量
            int cnt = r - l - 1;
            
            // 如果指数 cnt 过大，2^cnt 必然远超 X 的最大值 (1e9)
            if (cnt >= 60) {
                return 1; 
            }
    
            long long current_contribution = (1LL << cnt);
            total_subsequences += current_contribution;
    
            // 如果在累加过程中已经超过 X，直接判定错误，防止数据溢出
            if (total_subsequences > X) {
                return 1; 
            }
        }
    
        // 6. 最终比对：子序列总数必须恰好等于 X
        if (total_subsequences == X) {
            return 0; // return 0 代表程序正确 (AC)
        } else {
            return 1; // return 1 代表程序错误 (WA)
        }
    };

    while (_--) {
        if (ck()) {
            return 1;
        }
    }

    return 0;
}
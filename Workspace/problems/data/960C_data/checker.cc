#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

// 辅助函数：检查字符串是否是合法的 [1, 10^18 - 1] 之间的正整数
bool isValidNumber(const string& s, long long& val) {
    // 1. 过滤空字符或过长的字符串（10^18 是 19 位数，超过 19 位一定不合法）
    if (s.empty() || s.length() > 19) return false;
    
    // 2. 检查是否全为数字，且不能有前导零（除非就是 "0"）
    if (s[0] == '0') return false; // 题目要求 a[i] >= 1，所以前导零和单独的 "0" 都不合法
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    
    // 3. 转化为 stoull 检查精确边界
    // 因为最大长度限制在 19 位，unsigned long long 绝对不会溢出（ULL 最大可达 20 位）
    unsigned long long temp = stoull(s);
    
    // 检查范围：1 <= a[i] <= 10^18 - 1
    if (temp < 1 || temp >= 1000000000000000000ULL) {
        return false;
    }
    
    val = (long long)temp;
    return true;
}

int main() {
    // 1. 打开牛客网规定的标准文件
    ifstream fin("input");
    ifstream fuser("user_output");
    
    if (!fin.is_open() || !fuser.is_open()) {
        return 1; // 文件打开失败
    }

    int _;
    if (!(fin >> _)) {
        return 1;
    }

    // 2. 读取输入数据 X 和 d
    long long X, d;
    if (!(fin >> X >> d)) {
        return 1; 
    }

    // 3. 读取选手输出的第一个数 (n)
    int n;
    if (!(fuser >> n)) {
        return 1; 
    }

    // 判定 n 的范围是否合法 (1 <= n <= 10000)
    if (n <= 0 || n > 10000) {
        return 1; 
    }

    // 4. 读取选手的整个数组并使用 string 检查元素合法性
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        if (!(fuser >> s)) {
            return 1; // 选手输出的元素个数不足 n 个
        }
        
        // 关键修改：用字符串验证范围，防范 > 1<<64 的大数攻击
        if (!isValidNumber(s, a[i])) {
            return 1; // 格式不合法或越界
        }
    }

    // 5. 核心逻辑：排序并使用双指针计算合法子序列数量
    sort(a.begin(), a.end());

    long long total_subsequences = 0;
    int r = 0;

    for (int l = 0; l < n; ++l) {
        while (r < n && a[r] - a[l] < d) {
            r++;
        }
        
        int cnt = r - l - 1;
        
        // 如果指数 cnt 过大，2^cnt 必然远超 X 的最大值
        if (cnt >= 60) {
            return 1; 
        }

        long long current_contribution = (1LL << cnt);
        total_subsequences += current_contribution;

        // 防止数据溢出
        if (total_subsequences > X) {
            return 1; 
        }
    }

    // 6. 最终比对
    if (total_subsequences == X) {
        return 0; // AC
    } else {
        return 1; // WA
    }

    return 0;
}
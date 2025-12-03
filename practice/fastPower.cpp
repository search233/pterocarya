//fastPower

#include <iostream>
using namespace std; 

long long fastPower(long long a, int b) {
    long long res = 1;
    while (b > 0) {
        
        if (b & 1) res *= a; // 如果 b 的当前位是 1，乘以当前的 a
        
        a *= a;				 // 将 a 乘以 a，准备下一次迭代
        
        b >>= 1;			 // 将 b 右移一位，准备下一位的检查
    }
    return res;
}


int main() {
    long long a;	cin >> a;
    int b;			cin >> b;
    cout << "Result: " << fastPower(a, b) << endl;
    return 0;
}

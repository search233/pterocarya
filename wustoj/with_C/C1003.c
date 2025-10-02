//C1003

#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d", &a, &b);

    if( a > b ) {
        c = a; // 假设这里是处理a大于b的情况
    } else {
        c = b; // 假设这里是处理a小于或等于b的情况
    }
    
    printf("%d", c); // 输出变量c的值
    return 0;
}

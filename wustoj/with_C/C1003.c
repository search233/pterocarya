//C1003

#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d", &a, &b);

    if( a > b ) {
        c = a; // ���������Ǵ���a����b�����
    } else {
        c = b; // ���������Ǵ���aС�ڻ����b�����
    }
    
    printf("%d", c); // �������c��ֵ
    return 0;
}

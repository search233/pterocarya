//fastPower

#include <iostream>
using namespace std; 

long long fastPower(long long a, int b) {
    long long res = 1;
    while (b > 0) {
        
        if (b & 1) res *= a; // ��� b �ĵ�ǰλ�� 1�����Ե�ǰ�� a
        
        a *= a;				 // �� a ���� a��׼����һ�ε���
        
        b >>= 1;			 // �� b ����һλ��׼����һλ�ļ��
    }
    return res;
}


int main() {
    long long a;	cin >> a;
    int b;			cin >> b;
    cout << "Result: " << fastPower(a, b) << endl;
    return 0;
}

#include <stdio.h>
int count(int x)  //����123,�򷵻�ֵΪ100(��λ��)
{
    int count = 1;
    while (x > 9)
    {
        x /= 10;
        count *= 10;
    }
    return count;
}

int main()
{
    int n, flag;
    scanf("%d", &n);

    if (n < 0)  //�����������Ϊ����ʱ,ȡ�������෴��
    {
        printf("fu ");
        n = -n;
    }

    flag = count(n);  //��¼��������n��λ��
    while (flag)
    {
        int k = n / flag;  //ȡ������n�����λ����
        n %= flag;  //�޳�����n�����λ����

        switch (k)
        {
        case 0:
            printf("ling");
            break;
        case 1:
            printf("yi");
            break;
        case 2:
            printf("er");
            break;
        case 3:
            printf("san");
            break;
        case 4:
            printf("si");
            break;
        case 5:
            printf("wu");
            break;
        case 6:
            printf("liu");
            break;
        case 7:
            printf("qi");
            break;
        case 8:
            printf("ba");
            break;
        case 9:
            printf("jiu");
        }

        if (flag > 9)  //������һ��ƴ��ʱ����ո�
            printf(" ");
        flag /= 10;
    }
    return 0;
}

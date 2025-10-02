#include <stdio.h>
int count(int x)  //例如123,则返回值为100(算位数)
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

    if (n < 0)  //当输入的整数为负数时,取负数的相反数
    {
        printf("fu ");
        n = -n;
    }

    flag = count(n);  //记录输入整数n的位数
    while (flag)
    {
        int k = n / flag;  //取出整数n的最高位数字
        n %= flag;  //剔除整数n的最高位数字

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

        if (flag > 9)  //输出最后一个拼音时不打空格
            printf(" ");
        flag /= 10;
    }
    return 0;
}

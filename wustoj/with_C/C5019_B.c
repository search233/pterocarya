//C5019


#include <stdio.h>
#include <math.h>
int isprime(int n)  //判断一个数是否为素数
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;  //返回0不为素数

    return 1;  //返回1为素数
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    
    if (isprime(n))  //特判:如果n为素数,则只有因数1和n
        printf("1\n%d\n", n);
    else
    {
        int start = 0, l = 0;
        //i最大遍历只需遍历到根号n即可
        //因为连续因子序列是升序排列的
        //且无法使得一个开根号的项(对原数开根号)乘上比它还大的数仍然等于原数
        for (i = 2; i <= sqrt(n); i++)
        {
            //s记录连续因子序列的乘积
            long long s = 1;  

            //i确定连续因子序列的左端,j滑动确定连续因子序列的右端
            for (j = i; s * j <= n; j++)
            {
                s = s * j;
                //l记录连续因子序列的长度
                //n%s==0是判断此时的连续因子序列是否满足条件
                //且若此时连续因子序列的长度大于原来连续因子序列的长度则更新l
                //eg:比如题目给的例子:630=3*5*6*7
                //当找到5*6这个连续序列时,n%s等于0,则可以将长度更新为2
                //继续遍历,发现5*6*7这个连续序列也满足,则还可以将长度更新为3
                if (n % s == 0 && j - i + 1 > l)
                {
                    start = i;  //记录连续因子序列的左端点
                    //printf("%d\n", i); 
                    l = j - i + 1;  //不断更新l的值,以求出最大的l
                }
            }
        }

        printf("%d\n", l);
        //按照输出格式输出,最长连续因子序列的起始点为start,长度为l
        for (i = start; i < start + l; i++)
        {
            if (i == start)
                printf("%d", i);
            else
                printf("*%d", i);
        }
        printf("\n");
    }
    return 0;
}

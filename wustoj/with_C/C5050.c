//C5050

#include <stdio.h>

int main()
{
    char C[10000];

    int cnt = 0, flag = 0;

    fgets(C, sizeof(C), stdin);

    for (int i = 0;; i++) {

        if (C[i] != ' ' && C[i] != '\n' && C[i] != '\0' && C[i] != EOF) { //读取字符
            cnt++;
        }

        if ((C[i] == ' ' || C[i] == '\0' || C[i] == EOF) && cnt != 0) { //出现空格， 输出字符长度， 初始化cnt
            printf("%d ", cnt);
            cnt = 0;
            flag = 1;
        }

        if (C[i] == '\n' || C[i] == '\0' || C[i] == EOF) { //结束存在三种情况，包括EOF
            if (cnt != 0) { //以字符结尾时输出最后一组字符的个数
                printf("%d", cnt);
            }
            if (flag == 0) { //以空格结尾时判断之前是否存在字符
                printf("0");
            }
            //不存在则输出0， 存在则直接跳出
            break;
        }
    }

    return 0;
}

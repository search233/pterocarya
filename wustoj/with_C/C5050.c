//C5050

#include <stdio.h>

int main()
{
    char C[10000];

    int cnt = 0, flag = 0;

    fgets(C, sizeof(C), stdin);

    for (int i = 0;; i++) {

        if (C[i] != ' ' && C[i] != '\n' && C[i] != '\0' && C[i] != EOF) { //��ȡ�ַ�
            cnt++;
        }

        if ((C[i] == ' ' || C[i] == '\0' || C[i] == EOF) && cnt != 0) { //���ֿո� ����ַ����ȣ� ��ʼ��cnt
            printf("%d ", cnt);
            cnt = 0;
            flag = 1;
        }

        if (C[i] == '\n' || C[i] == '\0' || C[i] == EOF) { //���������������������EOF
            if (cnt != 0) { //���ַ���βʱ������һ���ַ��ĸ���
                printf("%d", cnt);
            }
            if (flag == 0) { //�Կո��βʱ�ж�֮ǰ�Ƿ�����ַ�
                printf("0");
            }
            //�����������0�� ������ֱ������
            break;
        }
    }

    return 0;
}

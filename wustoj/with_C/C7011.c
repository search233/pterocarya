//C7011


#include<stdio.h>

void move(int,char,char,char);

int main()
{
    int n;
    scanf("%d",&n);
    printf("the step to moving %2d diskes:\n",n);
    move(n,'a','b','c');
    return 0;
}



//void move( int n, char from_rod, char to_rod, char aux_rod) {

void move(int n, char from, char buf, char to) {	

    if (n == 1) {
        // ֻ��һ��Բ��ʱ��ֱ���ƶ���Ŀ������
        printf("%c-->%c\n", from, to);
        return;
    }
    
    // ��n-1��Բ�̴���ʼ�����ƶ�����������
    move(n - 1, from, to, buf);
    
    // ������Բ���ƶ���Ŀ������
    printf("%c-->%c\n", from, to);
    
    // ��n-1��Բ�̴Ӹ��������ƶ���Ŀ������
    move(n - 1, buf, from, to);
} 

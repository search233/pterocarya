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
        // 只有一个圆盘时，直接移动到目标柱子
        printf("%c-->%c\n", from, to);
        return;
    }
    
    // 将n-1个圆盘从起始柱子移动到辅助柱子
    move(n - 1, from, to, buf);
    
    // 将最大的圆盘移动到目标柱子
    printf("%c-->%c\n", from, to);
    
    // 将n-1个圆盘从辅助柱子移动到目标柱子
    move(n - 1, buf, from, to);
} 

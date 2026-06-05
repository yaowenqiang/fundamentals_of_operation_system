#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0;
    char* b;  // 野指针

    printf("b的初始地址: %p\n", (void*)b);

    scanf("%d", &a);
    printf("输入的整数: %d\n", a);

    scanf("%s", b);  // 危险！向随机地址写入
    printf("输入的字符串: %s\n", b);

    return 0;
}

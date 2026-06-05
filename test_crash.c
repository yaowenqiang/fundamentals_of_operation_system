#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a = 0;
    char* b = NULL;  // 显式设置为NULL

    printf("b的地址: %p\n", (void*)b);

    scanf("%d", &a);
    printf("输入的整数: %d\n", a);

    scanf("%s", b);  // 肯定会崩溃！向NULL地址写入
    printf("输入的字符串: %s\n", b);

    return 0;
}

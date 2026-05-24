#include <stdio.h>
#include <stddef.h>

struct Test {
    char a;
    int b;
    short c;
};

struct Example {
    char a; 
    short c;
    int b; 
};
/*
struct Example {
        char a;     // 1 字节，偏移量 = 0
                    //     // 填充 3 字节（保证 int 从 4 的倍数地址开始）
                    //         int b;      // 4 字节，偏移量 = 4
                    //             short c;    // 2 字节，偏移量 = 8
                    //                 // 填充 2 字节（保证结构体总大小为 4 的倍数）
                    //                 
};              // 总大小 = 12 字节（不是 1+4+2=7！）
                //
*/
int main() {
    printf("int 对齐要求: %zu\n", _Alignof(int));          // 通常输出 4
    printf("b 的偏移量: %zu\n", offsetof(struct Test, b)); // 输出 4
    printf("Test    总大小: %zu\n", sizeof(struct Test));          // 输出 12
    printf("Example 总大小: %zu\n", sizeof(struct Example));          // 输出 12
}

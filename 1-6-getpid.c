#include "apue.h"

int main() {
    // 查看进程号，非负整数，long 型可移植性好
    printf("hello world from process ID %ld\n", (long)(getpid()));
    return 0;
}
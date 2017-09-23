#include "apue.h"

int main() {
    // 用户 id 和 组 id
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    return 0;
}
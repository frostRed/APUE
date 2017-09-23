#include "apue.h"
#include <errno.h>

int main(int argc, char* argv[]) {
    // strerror 将错误码映射为错误消息字符串
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    // perror 在 stderr 中先打印 参数字符串，在打印冒号和 strerror(当前错误码)
    perror(argv[0]);
    return 0;
}
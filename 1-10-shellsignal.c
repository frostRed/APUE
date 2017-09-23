#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main() {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        err_sys("signal error");
    }

    printf("%% ");
    // fgets 读取一行，而且回车也会读进去
    while (fgets(buf, MAXLINE, stdin) != nullptr) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }
    }

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    }
    else if (pid == 0) {
        // 子进程
        execlp(buf, buf, (char*)0);
        err_ret("couldn't execute: %s", buf);
        exit(127);
    }

    // 父进程等待某个 pid 的子进程结束，防止僵尸进程，status 可传出子进程结束时的状态
    if ((pid == waitpid(pid, &status, 0)) < 0) {
        err_sys("waitpid error");
    }
    return 0;
}

void sig_int(int signo) {
    printf("interrupt \n%% ");
}
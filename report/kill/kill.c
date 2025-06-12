#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [PID]\n", argv);
return 1;
}

pid_t pid = atoi(argv);
if (kill(pid, SIGTERM) != 0) {
    perror("kill");
    return 1;
}

printf("PID %d에 SIGTERM 시그널 전송 완료\n", pid);
return 0;
}

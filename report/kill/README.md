# kill 명령어 구현

## 1. 명령어 설명
`kill`은 지정한 프로세스에 시그널(기본적으로 SIGTERM, 종료)을 보내는 명령어입니다.

## 2. 구동 원리
- `kill()` 시스템 콜을 사용하여 특정 PID에 시그널을 보냅니다.
- 기본 시그널은 SIGTERM(15)이며, 다른 시그널도 지정할 수 있습니다.
- 여기서는 SIGTERM만 지원하는 기본 버전입니다.

## 3. C 구현 코드
```c
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
```

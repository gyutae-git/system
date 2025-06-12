# cd 명령어 구현

## 1. 명령어 설명
`cd`(change directory)는 작업 디렉토리를 변경하는 명령어입니다.

## 2. 구동 원리
1. `chdir()` 시스템 콜을 사용해 현재 프로세스의 작업 디렉토리를 변경합니다.
2. 인자가 없으면 홈 디렉토리로 이동(여기서는 간단히 인자가 없으면 에러 처리).
3. 인자로 받은 경로로 이동 시도, 실패하면 에러 메시지 출력.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [디렉토리]\n", argv);
return 1;
}
if (chdir(argv) != 0) {
    perror("chdir");
    return 1;
}

// 이동 후 현재 디렉토리 출력(확인용)
char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("현재 디렉토리: %s\n", cwd);
} else {
    perror("getcwd");
}

return 0;
}
```

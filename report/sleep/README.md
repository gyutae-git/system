# sleep 명령어 구현

## 1. 명령어 설명
`sleep`은 지정한 시간(초) 동안 프로그램 실행을 일시 중지하는 명령어입니다.

## 2. 구동 원리
- `sleep()` 함수를 사용하여 지정한 초만큼 현재 프로세스를 일시 정지시킵니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [초]\n", argv);
return 1;
}

int sec = atoi(argv);
printf("%d초 동안 대기...\n", sec);
sleep(sec);
printf("대기 종료\n");
return 0;
}
```

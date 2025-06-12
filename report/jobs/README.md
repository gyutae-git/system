# jobs 명령어 구현

## 1. 명령어 설명
`jobs`는 백그라운드에서 실행 중인 작업(프로세스)의 목록과 상태를 출력하는 명령어입니다.

## 2. 구동 원리
- 실제로는 셸이 백그라운드 작업을 관리하며, 각 작업의 PID, 상태, 명령어를 출력합니다.
- C 프로그램에서 완벽하게 구현하기는 어렵지만, 여기서는 현재 로그인한 사용자의 백그라운드 프로세스를 `ps` 명령으로 간단히 출력합니다.

## 3. C 구현 코드 (system 함수 이용)
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
// 실제 jobs는 셸 내장 명령어이므로, ps로 대체
system("ps -o pid,stat,cmd --ppid $$ | grep '&'");
return 0;
}
```

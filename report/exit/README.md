# exit 명령어 구현

## 1. 명령어 설명
`exit`은 셸이나 프로그램을 종료하는 명령어입니다.

## 2. 구동 원리
- C 프로그램에서는 `exit()` 함수를 호출하거나, `return` 문으로 메인 함수에서 빠져나오면 프로세스가 종료됩니다.
- 인자가 있으면 해당 값을 종료 코드로 반환합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
int code = 0;
if (argc > 1) {
code = atoi(argv);
}
printf("프로그램을 종료합니다. (종료 코드: %d)\n", code);
exit(code);
}
```

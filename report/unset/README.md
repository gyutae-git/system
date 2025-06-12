# unset 명령어 구현

## 1. 명령어 설명
`unset`은 지정한 환경 변수(또는 셸 변수)를 삭제하는 명령어입니다.

## 2. 구동 원리
- C에서는 `unsetenv()` 함수를 사용해 환경 변수를 삭제합니다.
- 실제로는 셸 내장 명령어로, 셸 변수도 삭제할 수 있지만 여기서는 환경 변수만 처리합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [변수이름]\n", argv);
return 1;
}

if (unsetenv(argv) != 0) {
    perror("unsetenv");
    return 1;
}

printf("환경 변수 삭제: %s\n", argv);
return 0;
}
```

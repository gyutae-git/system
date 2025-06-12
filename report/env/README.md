# env 명령어 구현

## 1. 명령어 설명
`env`는 현재 환경 변수 목록을 출력하거나, 임시로 환경 변수를 설정한 뒤 명령어를 실행하는 명령어입니다.

## 2. 구동 원리
- 환경 변수 목록은 `environ` 전역 변수 배열에 저장되어 있습니다.
- 각 환경 변수를 한 줄씩 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>

extern char **environ;

int main(void) {
for (char **env = environ; *env != NULL; env++) {
printf("%s\n", *env);
}
return 0;
}
```

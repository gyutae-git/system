# pwd 명령어 구현

## 1. 명령어 설명
`pwd`(print working directory)는 현재 작업 중인 디렉토리의 전체 경로를 출력하는 명령어입니다.

## 2. 구동 원리
- `getcwd()` 함수를 사용하여 현재 프로세스의 작업 디렉토리 경로를 가져와 출력합니다.

## 3. C 구현 코드

```c
#include <stdio.h>
#include <unistd.h>

int main(void) {
char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("%s\n", cwd);
} else {
    perror("getcwd");
    return 1;
}

return 0;
}
```

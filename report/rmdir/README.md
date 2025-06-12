# rmdir 명령어 구현

## 1. 명령어 설명
`rmdir`(remove directory)는 비어 있는 디렉토리를 삭제하는 명령어입니다.

## 2. 구동 원리
- `rmdir()` 시스템 콜을 사용하여 지정한 디렉토리가 비어 있으면 삭제합니다.
- 디렉토리가 비어 있지 않거나 존재하지 않으면 에러가 발생합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [디렉토리명]\n", argv);
return 1;
}

if (rmdir(argv[1]) != 0) {
    perror("rmdir");
    return 1;
}

printf("디렉토리 '%s' 삭제 완료\n", argv[1]);
return 0;
}
```

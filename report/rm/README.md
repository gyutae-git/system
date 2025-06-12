# rm 명령어 구현

## 1. 명령어 설명
`rm`(remove)은 파일을 삭제하는 명령어입니다.

## 2. 구동 원리
- `remove()` 또는 `unlink()` 함수를 사용하여 지정한 파일을 삭제합니다.
- 파일이 존재하지 않거나 권한이 없으면 에러가 발생합니다.
- 여기서는 단일 파일만 삭제합니다.

## 3. C 구현 코드
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

if (remove(argv) != 0) {
    perror("remove");
    return 1;
}

printf("파일 '%s' 삭제 완료\n", argv);
return 0;
}
```

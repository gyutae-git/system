# mv 명령어 구현

## 1. 명령어 설명
`mv`(move)는 파일이나 디렉토리의 이름을 변경하거나, 다른 위치로 이동하는 명령어입니다.

## 2. 구동 원리
- `rename()` 함수를 사용하여 파일 또는 디렉토리의 이름을 변경하거나 위치를 이동합니다.
- 같은 파일 시스템 내에서만 동작하며, 다른 파일 시스템 간 이동은 동작하지 않습니다.

## 3. C 구현 코드
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [원본] [대상]\n", argv);
return 1;
}

if (rename(argv, argv) != 0) {
    perror("rename");
    return 1;
}

printf("'%s' → '%s' 이동/이름 변경 완료\n", argv, argv);
return 0;
}
```

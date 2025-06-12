# chmod 명령어 구현

## 1. 명령어 설명
`chmod`(change mode)은 파일이나 디렉토리의 권한을 변경하는 명령어입니다.

## 2. 구동 원리
- `chmod()` 시스템 콜을 사용하여 지정한 파일이나 디렉토리의 권한을 변경합니다.Settings

- 권한은 8진수(예: 755, 644)로 입력받아 처리합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [권한(8진수)] [파일명]\n", argv);
return 1;
}

mode_t mode = strtol(argv, NULL, 8);
if (chmod(argv, mode) != 0) {
    perror("chmod");
    return 1;
}

printf("파일 '%s'의 권한이 %o(8진수)로 변경되었습니다.\n", argv, mode);
return 0;
}
```

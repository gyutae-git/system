# mkdir 명령어 구현

## 1. 명령어 설명
`mkdir`(make directory)는 새로운 디렉토리를 생성하는 명령어입니다.

## 2. 구동 원리
- `mkdir()` 시스템 콜을 사용하여 지정한 이름의 새 디렉토리를 생성합니다.
- 디렉토리 생성 권한(모드)은 0755(소유자 읽기/쓰기/실행, 그룹 및 기타 읽기/실행)로 설정합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [디렉토리명]\n", argv);
return 1;
}
if (mkdir(argv, 0755) != 0) {
    perror("mkdir");
    return 1;
}

printf("디렉토리 '%s' 생성 완료\n", argv);
return 0;
}
```

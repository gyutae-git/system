# ln 명령어 구현

## 1. 명령어 설명
`ln`은 파일의 하드 링크 또는 심볼릭 링크(소프트 링크)를 생성하는 명령어입니다.

## 2. 구동 원리
- 하드 링크: `link()` 시스템 콜을 사용해 기존 파일의 또 다른 이름을 만듭니다.
- 심볼릭 링크: `symlink()` 시스템 콜을 사용해 경로를 가리키는 새 파일을 만듭니다.
- 여기서는 하드 링크만 기본으로 구현합니다.

## 3. C 구현 코드 (하드 링크)
```c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [원본파일] [링크이름]\n", argv);
return 1;
}

if (link(argv, argv) != 0) {
    perror("link");
    return 1;
}

printf("하드 링크 '%s' → '%s' 생성 완료\n", argv, argv);
return 0;
}
```

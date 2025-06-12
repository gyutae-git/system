# tar 명령어 구현

## 1. 명령어 설명
`tar`(tape archive)은 여러 파일을 하나의 아카이브 파일로 묶거나, 아카이브에서 파일을 추출하는 명령어입니다.

## 2. 구동 원리
- 실제 tar는 복잡한 파일 포맷을 사용하지만, 여기서는 여러 파일을 순서대로 하나의 파일로 단순하게 합치는 기능만 구현합니다.
- 각 파일의 이름과 크기를 먼저 기록한 후, 파일 내용을 이어붙입니다.

## 3. C 구현 코드 (여러 파일을 하나로 묶기)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [아카이브파일] [파일1] [파일2] ...\n", argv);
return 1;
}

FILE *archive = fopen(argv, "wb");
if (!archive) {
    perror("fopen");
    return 1;
}

for (int i = 2; i < argc; i++) {
    FILE *src = fopen(argv[i], "rb");
    if (!src) {
        perror("fopen");
        continue;
    }
    // 파일 이름과 크기 기록
    fseek(src, 0, SEEK_END);
    long size = ftell(src);
    fseek(src, 0, SEEK_SET);
    fprintf(archive, "%s %ld\n", argv[i], size);

    // 내용 복사
    char buf[BUF_SIZE];
    long left = size;
    while (left > 0) {
        size_t n = fread(buf, 1, left > BUF_SIZE ? BUF_SIZE : left, src);
        fwrite(buf, 1, n, archive);
        left -= n;
    }
    fclose(src);
}
fclose(archive);
printf("아카이브 파일 '%s' 생성 완료\n", argv);
return 0;
}
```

# zip 명령어 구현

## 1. 명령어 설명
`zip`은 여러 파일을 하나의 압축 파일로 묶는 명령어입니다.

## 2. 구동 원리
- 실제 zip은 복잡한 포맷과 압축 알고리즘을 사용하지만, 여기서는 zlib의 `compress()` 함수를 이용해 여러 파일을 각각 압축해서 하나의 파일에 저장합니다.
- 각 파일의 이름, 압축 전 크기, 압축 후 크기를 기록한 후, 압축 데이터를 이어붙입니다.

## 3. C 구현 코드 (zlib 필요, 매우 단순화)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [압축파일.zip] [파일1] [파일2] ...\n", argv);
return 1;
}

FILE *zip = fopen(argv, "wb");
if (!zip) {
    perror("fopen");
    return 1;
}

for (int i = 2; i < argc; i++) {
    FILE *src = fopen(argv[i], "rb");
    if (!src) {
        perror("fopen");
        continue;
    }
    fseek(src, 0, SEEK_END);
    long src_size = ftell(src);
    fseek(src, 0, SEEK_SET);

    unsigned char *src_buf = malloc(src_size);
    fread(src_buf, 1, src_size, src);
    fclose(src);

    uLongf comp_size = compressBound(src_size);
    unsigned char *comp_buf = malloc(comp_size);

    if (compress(comp_buf, &comp_size, src_buf, src_size) != Z_OK) {
        fprintf(stderr, "압축 실패: %s\n", argv[i]);
        free(src_buf);
        free(comp_buf);
        continue;
    }

    // 파일 이름, 원본 크기, 압축 크기 기록
    fprintf(zip, "%s %ld %lu\n", argv[i], src_size, comp_size);
    fwrite(comp_buf, 1, comp_size, zip);

    free(src_buf);
    free(comp_buf);
}
fclose(zip);
printf("압축 파일 '%s' 생성 완료\n", argv);
return 0;
}
```

# gzip 명령어 구현

## 1. 명령어 설명
`gzip`은 파일을 압축하는 명령어입니다.

## 2. 구동 원리
- 실제 gzip은 DEFLATE 알고리즘을 사용하지만, 여기서는 표준 라이브러리의 zlib을 이용해 간단히 구현합니다.
- 입력 파일을 읽어서 zlib의 `compress()` 함수로 압축한 뒤, `.gz` 확장자 파일로 저장합니다.

## 3. C 구현 코드 (zlib 필요)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

FILE *src = fopen(argv, "rb");
if (!src) {
    perror("fopen");
    return 1;
}

fseek(src, 0, SEEK_END);
long src_size = ftell(src);
fseek(src, 0, SEEK_SET);

unsigned char *src_buf = malloc(src_size);
fread(src_buf, 1, src_size, src);
fclose(src);

uLongf dest_size = compressBound(src_size);
unsigned char *dest_buf = malloc(dest_size);

if (compress(dest_buf, &dest_size, src_buf, src_size) != Z_OK) {
    fprintf(stderr, "압축 실패\n");
    free(src_buf);
    free(dest_buf);
    return 1;
}

char outname[1024];
snprintf(outname, sizeof(outname), "%s.gz", argv);

FILE *dest = fopen(outname, "wb");
fwrite(dest_buf, 1, dest_size, dest);
fclose(dest);

printf("압축 완료: %s → %s (원본 %ld bytes, 압축 %lu bytes)\n", argv, outname, src_size, dest_size);

free(src_buf);
free(dest_buf);
return 0;
}
```

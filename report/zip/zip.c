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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [압축파일.zip]\n", argv);
return 1;
}

FILE *zip = fopen(argv, "rb");
if (!zip) {
    perror("fopen");
    return 1;
}

while (1) {
    char filename;
    long orig_size;
    unsigned long comp_size;

    if (fscanf(zip, "%s %ld %lu\n", filename, &orig_size, &comp_size) != 3) {
        break; // 더 이상 파일 없음
    }

    unsigned char *comp_buf = malloc(comp_size);
    fread(comp_buf, 1, comp_size, zip);

    unsigned char *orig_buf = malloc(orig_size);
    uLongf dest_len = orig_size;

    if (uncompress(orig_buf, &dest_len, comp_buf, comp_size) != Z_OK) {
        fprintf(stderr, "압축 해제 실패: %s\n", filename);
        free(comp_buf);
        free(orig_buf);
        continue;
    }

    FILE *out = fopen(filename, "wb");
    fwrite(orig_buf, 1, dest_len, out);
    fclose(out);

    printf("압축 해제 완료: %s\n", filename);

    free(comp_buf);
    free(orig_buf);
}

fclose(zip);
return 0;
}

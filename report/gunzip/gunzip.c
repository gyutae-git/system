#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define BUF_SIZE 4096
#define MAX_ORIG_SIZE (10010241024) // 최대 100MB까지 복원 허용

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [압축파일.gz]\n", argv);
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

unsigned char *dest_buf = malloc(MAX_ORIG_SIZE);
uLongf dest_size = MAX_ORIG_SIZE;

if (uncompress(dest_buf, &dest_size, src_buf, src_size) != Z_OK) {
    fprintf(stderr, "압축 해제 실패\n");
    free(src_buf);
    free(dest_buf);
    return 1;
}

// .gz 확장자 제거
char outname[1024];
strncpy(outname, argv, sizeof(outname));
char *dot = strstr(outname, ".gz");
if (dot) *dot = '\0';

FILE *dest = fopen(outname, "wb");
fwrite(dest_buf, 1, dest_size, dest);
fclose(dest);

printf("압축 해제 완료: %s → %s (압축 %ld bytes, 해제 %lu bytes)\n", argv, outname, src_size, dest_size);

free(src_buf);
free(dest_buf);
return 0;
}

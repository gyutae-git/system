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

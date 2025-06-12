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

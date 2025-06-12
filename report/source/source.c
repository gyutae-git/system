#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [스크립트파일]\n", argv);
return 1;
}

FILE *fp = fopen(argv, "r");
if (!fp) {
    perror("fopen");
    return 1;
}

char buf[BUF_SIZE];
while (fgets(buf, sizeof(buf), fp)) {
    // 줄 끝 개행 제거
    buf[strcspn(buf, "\n")] = '\0';
    if (buf == '\0') continue;
    printf("실행: %s\n", buf);
    system(buf);
}
fclose(fp);
return 0;
}

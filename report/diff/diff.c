#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [파일1] [파일2]\n", argv);
return 1;
}

FILE *fp1 = fopen(argv, "r");
FILE *fp2 = fopen(argv, "r");
if (!fp1 || !fp2) {
    perror("fopen");
    return 1;
}

char buf1[BUF_SIZE], buf2[BUF_SIZE];
int line = 1;
while (fgets(buf1, sizeof(buf1), fp1) && fgets(buf2, sizeof(buf2), fp2)) {
    if (strcmp(buf1, buf2) != 0) {
        printf("%d: %s|%s", line, buf1, buf2);
    }
    line++;
}
// 남은 줄 처리
while (fgets(buf1, sizeof(buf1), fp1)) {
    printf("%d: %s|(없음)\n", line++, buf1);
}
while (fgets(buf2, sizeof(buf2), fp2)) {
    printf("%d: (없음)|%s", line++, buf2);
}

fclose(fp1);
fclose(fp2);
return 0;
}

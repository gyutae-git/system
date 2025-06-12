#include <stdio.h>

#define PAGE_LINES 20
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

FILE *fp = fopen(argv, "r");
if (!fp) {
    perror("fopen");
    return 1;
}

char buf[BUF_SIZE];
int count = 0;

while (fgets(buf, sizeof(buf), fp)) {
    printf("%s", buf);
    count++;
    if (count % PAGE_LINES == 0) {
        printf("-- 다음 페이지를 보려면 스페이스바를 누르세요 --");
        while (getchar() != ' '); // 스페이스바 입력 대기
        printf("\n");
    }
}

fclose(fp);
return 0;
}

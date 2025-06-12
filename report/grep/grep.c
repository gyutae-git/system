#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [검색문자열] [파일명]\n", argv);
return 1;
}

const char *pattern = argv;
FILE *fp = fopen(argv, "r");
if (!fp) {
    perror("fopen");
    return 1;
}

char buf[BUF_SIZE];
while (fgets(buf, sizeof(buf), fp)) {
    if (strstr(buf, pattern)) {
        printf("%s", buf);
    }
}

fclose(fp);
return 0;
}

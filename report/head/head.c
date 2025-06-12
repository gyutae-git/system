#include <stdio.h>

#define MAX_LINES 10
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
while (fgets(buf, sizeof(buf), fp) && count < MAX_LINES) {
    printf("%s", buf);
    count++;
}

fclose(fp);
return 0;
}

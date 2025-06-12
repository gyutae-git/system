#include <stdio.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [명령어이름]\n", argv);
return 1;
}

char filename;
snprintf(filename, sizeof(filename), "%s.txt", argv);

FILE *fp = fopen(filename, "r");
if (!fp) {
    perror("fopen");
    return 1;
}

char buf[BUF_SIZE];
while (fgets(buf, sizeof(buf), fp)) {
    printf("%s", buf);
}

fclose(fp);
return 0;
}

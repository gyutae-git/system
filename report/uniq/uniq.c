#include <stdio.h>
#include <string.h>

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

char prev[BUF_SIZE] = "";
char curr[BUF_SIZE];

while (fgets(curr, sizeof(curr), fp)) {
    if (strcmp(prev, curr) != 0) {
        printf("%s", curr);
        strcpy(prev, curr);
    }
}

fclose(fp);
return 0;
}

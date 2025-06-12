#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define BUF_SIZE 1024

int cmp(const void *a, const void *b) {
const char *sa = *(const char **)a;
const char *sb = *(const char **)b;
return strcmp(sa, sb);
}

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

char *lines[MAX_LINES];
char buf[BUF_SIZE];
int count = 0;

while (fgets(buf, sizeof(buf), fp) && count < MAX_LINES) {
    lines[count] = strdup(buf);
    count++;
}
fclose(fp);

qsort(lines, count, sizeof(char *), cmp);

for (int i = 0; i < count; i++) {
    printf("%s", lines[i]);
    free(lines[i]);
}
return 0;
}

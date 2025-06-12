# sort 명령어 구현

## 1. 명령어 설명
`sort`는 파일의 각 줄을 오름차순으로 정렬하여 출력하는 명령어입니다.

## 2. 구동 원리
- 파일의 모든 줄을 메모리(배열)에 저장합니다.
- 저장된 줄들을 `qsort()` 등으로 정렬합니다.
- 정렬된 결과를 출력합니다.

## 3. C 구현 코드
```c
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
```

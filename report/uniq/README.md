# uniq 명령어 구현

## 1. 명령어 설명
`uniq`는 파일에서 연속적으로 중복된 줄을 제거하고 한 번씩만 출력하는 명령어입니다.

## 2. 구동 원리
- 파일을 한 줄씩 읽어 이전 줄과 비교합니다.
- 이전 줄과 다르면 출력하고, 같으면 출력하지 않습니다.

## 3. C 구현 코드
```c
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
```

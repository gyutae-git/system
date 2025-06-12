# diff 명령어 구현

## 1. 명령어 설명
`diff`는 두 파일을 비교하여 서로 다른 부분(라인)을 출력하는 명령어입니다.

## 2. 구동 원리
- 두 파일을 한 줄씩 읽어가며 비교합니다.
- 각 줄이 다르면 줄 번호와 함께 두 파일의 내용을 출력합니다.
- 여기서는 두 파일의 줄 수가 다를 경우 짧은 쪽에 맞춰 비교합니다.

## 3. C 구현 코드
```c
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
```

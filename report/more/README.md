# more 명령어 구현

## 1. 명령어 설명
`more`는 파일의 내용을 한 화면(페이지)씩 출력하고, 사용자가 엔터나 스페이스바를 눌러 다음 내용을 볼 수 있게 하는 명령어입니다.

## 2. 구동 원리
- 파일을 `fopen()`으로 연 후, 한 줄씩 읽어 화면에 출력합니다.
- 한 화면(여기서는 20줄)씩 출력하고, 사용자 입력(엔터 또는 스페이스바 등)을 기다려 다음 페이지를 출력합니다.
- 입력은 `getchar()`로 처리합니다.

## 3. C 구현 코드
```c
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
        printf("-- 다음 페이지를 보려면 엔터 또는 스페이스바를 누르세요 --");
        int c = getchar();
        while (c != '\n' && c != ' ') {
            c = getchar();
        }
        printf("\n");
    }
}

fclose(fp);
return 0;
}
```

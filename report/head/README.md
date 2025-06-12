# head 명령어 구현

## 1. 명령어 설명
`head`는 파일의 처음 몇 줄(기본 10줄)을 출력하는 명령어입니다.

## 2. 구동 원리
- 파일을 `fopen()`으로 읽기 모드로 엽니다.
- `fgets()`를 사용해 한 줄씩 읽으면서, 최대 10줄까지 출력합니다.
- 파일을 다 읽거나 10줄을 출력하면 종료합니다.

## 3. C 구현 코드
```c
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
```

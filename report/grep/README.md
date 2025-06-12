# grep 명령어 구현

## 1. 명령어 설명
`grep`(global regular expression print)은 파일에서 특정 문자열이 포함된 줄을 찾아 출력하는 명령어입니다.

## 2. 구동 원리
- 파일을 `fopen()`으로 연 후, 한 줄씩 읽어옵니다.
- 각 줄에서 `strstr()` 함수를 이용해 검색 문자열이 포함되어 있는지 확인합니다.
- 포함된 줄만 출력합니다.

## 3. C 구현 코드
```c
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
```

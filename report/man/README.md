# man 명령어 구현

## 1. 명령어 설명
`man`(manual)은 명령어의 매뉴얼 페이지(도움말)를 출력하는 명령어입니다.

## 2. 구동 원리
- 실제 `man`은 `/usr/share/man` 등에서 압축된 매뉴얼 파일을 찾아 `less` 등으로 출력합니다.
- 여기서는 간단하게 명령어 이름에 해당하는 텍스트 파일(예: `ls.txt`)을 현재 디렉토리에서 찾아 출력합니다.

## 3. C 구현 코드
```c
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
```

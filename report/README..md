# cp 명령어 구현

## 1. 명령어 설명
`cp`(copy)는 파일을 복사하는 명령어입니다.

## 2. 구동 원리
- 원본 파일을 `open()`으로 읽기 모드로 엽니다.
- 대상 파일을 `open()`으로 쓰기(필요시 생성) 모드로 엽니다.
- `read()`와 `write()`를 사용해 원본 파일의 내용을 대상 파일로 복사합니다.
- 파일을 모두 복사한 후 `close()`로 파일을 닫습니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [원본파일] [대상파일]\n", argv);
return 1;
}

int src = open(argv, O_RDONLY);
if (src < 0) {
    perror("원본 파일 열기 실패");
    return 1;
}

int dest = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (dest < 0) {
    perror("대상 파일 열기 실패");
    close(src);
    return 1;
}

char buf[BUF_SIZE];
ssize_t n;
while ((n = read(src, buf, BUF_SIZE)) > 0) {
    if (write(dest, buf, n) != n) {
        perror("쓰기 오류");
        close(src);
        close(dest);
        return 1;
    }
}

close(src);
close(dest);
printf("'%s' → '%s' 복사 완료\n", argv, argv);
return 0;
}
```

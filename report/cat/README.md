# cat 명령어 구현

## 1. 명령어 설명
`cat`(concatenate and display files)은 파일의 내용을 표준 출력(화면)에 출력하는 명령어입니다. 여러 파일을 연속해서 출력하거나, 리다이렉션을 통해 파일을 합칠 수도 있습니다.

## 2. 구동 원리
- `open()` 함수로 파일을 읽기 모드로 엽니다.
- `read()`로 파일 내용을 버퍼에 읽고, `write()` 또는 `printf()`로 표준 출력에 출력합니다.
- 여러 파일을 연속해서 출력할 수 있지만, 여기서는 단일 파일만 처리하는 기본 버전입니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

int fd = open(argv[1], O_RDONLY);
if (fd < 0) {
    perror("open");
    return 1;
}

char buf[BUF_SIZE];
ssize_t n;
while ((n = read(fd, buf, BUF_SIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
        perror("write");
        close(fd);
        return 1;
    }
}

close(fd);
return 0;
}
```

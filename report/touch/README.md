# touch 명령어 구현

## 1. 명령어 설명
`touch` 명령어는 지정한 파일이 없으면 새로 생성하고, 이미 존재하면 파일의 최종 수정 시간을 현재 시간으로 갱신합니다.

## 2. 구동 원리
- 파일이 존재하지 않으면 `open()` 함수의 `O_CREAT` 플래그로 새 파일을 생성합니다.
- 파일이 존재하면 `utime()` 또는 `utimensat()` 함수를 사용해 수정 시간을 현재로 변경합니다.
- 여기서는 파일 생성 및 시간 갱신을 위해 `open()`과 `close()`만 사용합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

int fd = open(argv, O_CREAT | O_WRONLY, 0644);
if (fd == -1) {
    perror("open");
    return 1;
}

close(fd);
printf("'%s' 파일 touch 완료\n", argv);
return 0;
}
```
